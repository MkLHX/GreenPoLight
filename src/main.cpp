/**
 *
 * @file main.cpp
 * @author Mickael Lehoux (mickael@lehoux.net)
 * @brief GreenPoLight firmware
 * @version 0.1
 * @date 2020-09-22
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <main.h>

void fillLeds(Adafruit_NeoPixel &strip, uint32_t ledcolor)
{
    strip.fill(ledcolor);
    strip.show();
}

void fillOneLed(Adafruit_NeoPixel &strip, int pixel, uint32_t ledcolor)
{
    strip.setPixelColor(pixel, ledcolor);
    strip.show();
}

void clearLeds(Adafruit_NeoPixel &strip)
{
    strip.fill(ledColors.black);
    strip.show();
}

void ArrowRight(uint32_t color, uint8_t wait)
{
    for (int j = 0; j < 1; j++)
    { // The j<# determines how many cycles
        for (uint16_t i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, color);
            strip.show();
            delay(wait);
        }
        for (uint16_t i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);
    }
}

void ArrowLeft(uint32_t color, uint8_t wait)
{
    for (int j = 0; j < 1; j++)
    { // The j<# determines how many cycles
        for (uint16_t i = strip.numPixels(); i + 1 > 0; i--)
        {
            strip.setPixelColor(i, color);
            strip.show();
            delay(wait);
        }
        for (uint16_t i = strip.numPixels(); i + 1 > 0; i--)
        {
            strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);
    }
}

void WigWag(uint32_t color, uint8_t wait)
{
    for (int j = 0; j < 5; j++)
    { // The j<# determines how many cycles
        for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color);
        }
        for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);

        for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, 0);
        }
        for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color);
        }
        strip.show();
        delay(wait);
    }
}

void WigWag2(uint32_t color, uint32_t color2, uint8_t wait)
{
    for (int j = 0; j < 5; j++)
    { // The j<# determines how many cycles
        for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color);
        }
        for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color2);
        }
        strip.show();
        delay(wait);

        for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color2);
        }
        for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
        {
            strip.setPixelColor(i, color);
        }
        strip.show();
        delay(wait);
    }
}

void red(uint32_t color, uint8_t wait) //passed color (c) and delay (wait) values
{
    int i = 0;           //start at pixel 0
    while (i < LEDS / 2) //loop until you reach half the pixels
    {
        strip.setPixelColor(i, color); //sets the pixel and color
        i++;
    }
    strip.show(); //turns on the pixels
    delay(wait);  //wait designated time (wait)
} //end red

void blue(uint32_t color, uint8_t wait) //passed color (c) and delay (wait) values
{
    int i = LEDS + 1;        //start at the last pixel
    while (i > LEDS / 2 - 1) //loop until you reach half the pixels
    {
        strip.setPixelColor(i, color); //sets pixel and color
        i--;
    }
    strip.show(); //turns on pixels
    delay(wait);  //wait designated time (wait)
} //end blue

/**
 * @brief red flash looks like police lights
 *
 */
void RedFlash()
{
    for (int x = 0; x <= 3; x++)
    {
        red(ledColors.red, 10); // call Red funtion - pass it color and dleay values
        clearLeds(strip);       // Turn off all pixels
        delay(75);
    }
} //end RedFlash

void BlueFlash()
{
    for (int x = 0; x <= 3; x++)
    {
        blue(ledColors.blue, 10); //call blue funtion - pass it color and dleay values
        clearLeds(strip);         // Turn off all pixels
        delay(75);
    }
} //end BlueFlash

// void Flash(uint32_t color, uint8_t wait = 10)
// {
//     for (int x = 0; x <= 3; x++)
//     {
//         int led = 0;             //start at pixel 0
//         int last_led = LEDS / 2; // end at half pixel

//         while (led < last_led) //loop until you reach half the pixels
//         {
//             strip.setPixelColor(led, color); //sets the pixel and color
//             led++;
//         }

//         strip.show();     //turns on the pixels
//         delay(wait);      //wait designated time (wait)
//         clearLeds(strip); // Turn off all pixels
//         delay(75);
//     }
//     for (int x = 0; x <= 3; x++)
//     {
//         int led1 = LEDS + 1;          //start at the last pixel
//         int last_led1 = LEDS / 2 - 1; // end at half pixel

//         while (led1 > last_led1) //loop until you reach half the pixels
//         {
//             strip.setPixelColor(led1, color); //sets the pixel and color
//             led1--;
//         }

//         strip.show();     //turns on the pixels
//         delay(wait);      //wait designated time (wait)
//         clearLeds(strip); // Turn off all pixels
//         delay(75);
//     }
// } //end Flash

void Police()
{
    RedFlash();
    delay(50);
    BlueFlash();
    delay(100);
} // end Police

void USPolice()
{
    WigWag(ledColors.red, 200);
    clearLeds(strip);
    Police();
    clearLeds(strip);
    WigWag(ledColors.blue, 200);
    clearLeds(strip);
    Police();
    delay(100);
}

void NightRider()
{
    for (int i = 0; i < (int)strip.numPixels(); i++)
    {
        fillOneLed(strip, i, ledColors.red);
        fillOneLed(strip, i - 1, strip.Color(150, 0, 0));
        fillOneLed(strip, i - 2, strip.Color(75, 0, 0));
        fillOneLed(strip, i - 3, strip.Color(25, 0, 0));
        fillOneLed(strip, i - 4, strip.Color(0, 0, 0));
        delay(50);
    }
    for (int i = (int)strip.numPixels(); i + 1 > 0; i--)
    {
        fillOneLed(strip, i, ledColors.red);
        fillOneLed(strip, i + 1, strip.Color(150, 0, 0));
        fillOneLed(strip, i + 2, strip.Color(75, 0, 0));
        fillOneLed(strip, i + 3, strip.Color(25, 0, 0));
        fillOneLed(strip, i + 4, strip.Color(0, 0, 0));
        delay(50);
    }
} // end NightRider

/**
 * @brief Last Debounce Time stored > input noise filter
 *
 */
unsigned long lastDebounceTime;

/**
 * @brief Delay between button pressed 2 times acceptance
 *
 */
unsigned long debounceDelay = 200;

bool isPoliceMode = false, isUSPoliceMode = false, k2000 = false;
int clicks;

void setup()
{
    Serial.begin(115200);
    pinMode(LEDSPIN, OUTPUT);
    pinMode(BUTTON, INPUT);
    digitalWrite(BUTTON, LOW);
    /**
     * @brief Init neopixel
     *
     */
    strip.setPin(LEDSPIN);
    strip.updateLength(LEDS);
    strip.updateType(NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
    /**
     * @brief execute every 1000 ms
     *
     */
    static unsigned long lastReadMillis = 0;
    if ((isPoliceMode || isUSPoliceMode || k2000) && (millis() - lastReadMillis > 1000))
    {
        if (isPoliceMode)
        {
            Police();
        }
        if (isUSPoliceMode)
        {
            USPolice();
        }
        if (k2000)
        {
            NightRider();
        }
        lastReadMillis = millis();
    }
    /**
     * @brief
     *
     */
    int buttonTrigged = digitalRead(BUTTON);
    /**
     * @brief debounce physicals buttons
     *
     */
    bool debounced = (millis() - lastDebounceTime) > debounceDelay;
    if (buttonTrigged && debounced)
    {
        clicks++;
        Serial.print(F("Clicks value: "));
        Serial.println(clicks);
        lastDebounceTime = millis();
    }

    // force mode to false avoid putit on each cases
    isPoliceMode = isUSPoliceMode = k2000 = false;
    switch (clicks)
    {
    case 1: // switch leds white
    {
        fillLeds(strip, ledColors.white);
        break;
    }
    case 2: // switch leds green
    {
        fillLeds(strip, ledColors.green);
        break;
    }
    case 3: // switch leds purple
    {
        fillLeds(strip, ledColors.purple);
        break;
    }
    case 4: // switch leds blue
    {
        fillLeds(strip, ledColors.blue);
        break;
    }
    case 5: // switch leds yellow
    {
        fillLeds(strip, ledColors.yellow);
        break;
    }
    case 6: // switch leds red
    {
        fillLeds(strip, ledColors.red);
        break;
    }
    case 7: // switch police mode
    {
        isPoliceMode = true;
        break;
    }
    case 8: // switch US police
    {
        isUSPoliceMode = true;
        break;
    }
    case 9: // switch k2000
    {
        k2000 = true;
        break;
    }
    default:
        clicks = 0;
        clearLeds(strip);
    }
}
