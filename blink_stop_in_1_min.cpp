// To stop the LED from blinking after 1 minute, you can use a timer to track how much time has passed and then exit the loop after 60 seconds.
#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

int main()
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1   // LD1 [GREEN]
    DigitalOut led(LED1);
#else
    bool led;
#endif

    Timer timer;
    timer.start();  // Start the timer

    while (true) {
        if (timer.elapsed_time() >= 60s) {
            led = 0;  // Turn off LED before stopping
            break;    // Exit the loop after 1 minute
        }

        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }

    // Optional: stay idle forever after stopping
    while (true) {
        // Do nothing
    }
}
