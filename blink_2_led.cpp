#include "InterfaceDigitalOut.h"
#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 500ms

int main() {
  // Initialise the digital pin LED1 as an output
#ifdef LED1 // LD1 [GREEN]
  DigitalOut led1(LED1);
  DigitalOut led2(LED2); // Built-in LED2 or define a pin like PB_14
#else
  bool led1;
  bool led2;
#endif

  Timer timer;
  timer.start(); // Start the timer

  while (true) {
    if (timer.elapsed_time() >= 60s) {
      led1 = 0; // Turn off LED before stopping
      led2 = 0;
      break; // Exit the loop after 1 minute
    }

    led1 = !led1;
    led2 = !led2;
    ThisThread::sleep_for(BLINKING_RATE);
  }
}
