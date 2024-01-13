#include "const.h"
#include "ws2812.pio.h"

void ws2812_put_rgb(uint8_t red, uint8_t green, uint8_t blue) {
  pio_sm_restart(LED_PIO, LED_SM);

  // write the rgb
  uint32_t mask = (red << 16) | (green << 8) | (blue << 0);
  pio_sm_put_blocking(LED_PIO, LED_SM, mask << 8u);
}

void ws2812_init() {
  pio_sm_set_enabled(LED_PIO, LED_SM, false);
  pio_sm_restart(LED_PIO, LED_SM);

  uint offset = pio_add_program(LED_PIO, &ws2812_program);

  pio_gpio_init(LED_PIO, LED_PIN);
  pio_sm_set_consecutive_pindirs(LED_PIO, LED_SM, LED_PIN, 1, true);

  pio_sm_config conf = ws2812_program_get_default_config(offset);
  sm_config_set_sideset_pins(&conf, LED_PIN);
  sm_config_set_out_shift(&conf, false, true, 32);
  sm_config_set_fifo_join(&conf, PIO_FIFO_JOIN_TX);

  int cycles_per_bit = 10;
  float div = clock_get_hz(clk_sys) / (800000 * cycles_per_bit);
  sm_config_set_clkdiv(&conf, div);

  pio_sm_init(LED_PIO, LED_SM, offset, &conf);
  pio_sm_set_enabled(LED_PIO, LED_SM, true);
}

void ws2812_reset() {
  // turn it off
  ws2812_put_rgb(0, 0, 0);
  pio_sm_set_enabled(LED_PIO, LED_SM, false);
  pio_sm_restart(LED_PIO, LED_SM);
}
