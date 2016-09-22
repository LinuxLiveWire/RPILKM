#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h> // for the GPIO functions
#include <linux/interrupt.h> // for the IRQ code

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Derek Molloy"); // The author visible with modinfo
MODULE_DESCRIPTION("A simple Linux LKM for the RPi."); // desc.
MODULE_VERSION("0.1");

static unsigned int gpioLED = 17; // pin 11 (GPIO17)
static unsigned int gpioButton = 27; // pin 13 (GPIO27)
static unsigned int irqNumber; // share IRQ num within file
static unsigned int numberPresses = 0; // store number of presses
static bool ledOn = 0; // used to invert state of LED
