#include "const.h"
#include "pico/stdio.h"
#include "ws2812.h"
#include <stdio.h>

int main() {
  stdio_init_all();

  // set the LED to white
  ws2812_init();
  ws2812_put_rgb(0xff, 0xff, 0xff);

  // we will wait for a USB connection for debugging (optional)
  wait_for_usb();

  // this is where you should do actual work
  printf("Hello, world!");

  // clear the LED
  ws2812_reset();
}
