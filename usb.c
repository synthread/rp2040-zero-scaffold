#include "const.h"
#include "hardware/pio.h"
#include "pico/stdio.h"
#include "pico/stdio_usb.h"
#include "pico/stdlib.h"
#include "ws2812.h"
#include <stdio.h>

void wait_for_usb() {
  printf("waiting for usb host");
  bool loop = false;
  while (!stdio_usb_connected()) {
    printf(".");
    sleep_ms(500);

    if (loop) {
      ws2812_put_rgb(0x00, 0x00, 0x00);
      loop = false;
    } else {
      ws2812_put_rgb(0xff, 0xff, 0xff);
      loop = true;
    }
  }
  printf("\nusb host detected\n");
}
