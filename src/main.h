/**
 * 
 * @file main.h
 * @author Mickael Lehoux (mickael@lehoux.net)
 * @brief GreenPoLight firmware
 * @version 0.1
 * @date 2020-09-22
 *
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MAIN_H
#define MAIN_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// #include <lights.h>

#define ARRAY_SIZE(arr) int(sizeof(arr) / sizeof(arr[0]))

#define LEDSPIN 2
#define BUTTON 3
// #define LEDS 20
#define LEDS 130


/**
 * @brief NeoPixel strip instance
 * 
 */
Adafruit_NeoPixel strip;

/**
 * @brief RBG colors presets
 * 
 */
struct Colors
{
    uint32_t red = strip.Color(255, 0, 0);       // red
    uint32_t green = strip.Color(0, 255, 0);     // green
    uint32_t blue = strip.Color(0, 0, 255);      // blue
    uint32_t white = strip.Color(255, 255, 255); // white
    uint32_t yellow = strip.Color(255, 255, 0);  // yellow
    uint32_t purple = strip.Color(255, 0, 255);  // purple
    uint32_t black = strip.Color(0, 0, 0);       // black
};

/**
 * @brief instanciate colors
 * 
 */
Colors ledColors;
#endif // MAIN_H