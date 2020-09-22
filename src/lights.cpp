// #include <lights.h>

// void ArrowRight(uint32_t color, uint8_t wait)
// {
//     for (int j = 0; j < 4; j++)
//     { // The j<# determines how many cycles
//         for (uint16_t i = 0; i < strip.numPixels(); i++)
//         {
//             strip.setPixelColor(i, color);
//             strip.show();
//             delay(wait);
//         }
//         for (uint16_t i = 0; i < strip.numPixels(); i++)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         strip.show();
//         delay(wait);
//     }
// }

// void ArrowLeft(uint32_t color, uint8_t wait)
// {
//     for (int j = 0; j < 4; j++)
//     { // The j<# determines how many cycles
//         for (uint16_t i = strip.numPixels(); i + 1 > 0; i--)
//         {
//             strip.setPixelColor(i, color);
//             strip.show();
//             delay(wait);
//         }
//         for (uint16_t i = strip.numPixels(); i + 1 > 0; i--)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         strip.show();
//         delay(wait);
//     }
// }

// void WigWag(uint32_t color, uint8_t wait)
// {
//     for (int j = 0; j < 10; j++)
//     { // The j<# determines how many cycles
//         for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, color);
//         }
//         for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         strip.show();
//         delay(wait);

//         for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, color);
//         }
//         strip.show();
//         delay(wait);
//     }
// }

// void WigWag2(uint32_t color, uint32_t color2, uint8_t wait)
// {
//     for (int j = 0; j < 20; j++)
//     { // The j<# determines how many cycles
//         for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, color);
//         }
//         for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         strip.show();
//         delay(wait);

//         for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, 0);
//         }
//         for (int i = ((int)strip.numPixels() / 2); i < (int)strip.numPixels(); i = i + 1)
//         {
//             strip.setPixelColor(i, color2);
//         }
//         strip.show();
//         delay(wait);
//     }
// }

// void BlinkOuter(uint32_t color, uint8_t wait)
// {
//     for (int j = 0; j < 10; j++)
//     { // The j<# determines how many cycles
//         strip.setPixelColor(strip.numPixels() - 1, color);
//         strip.setPixelColor(0, color);
//         strip.show();
//         delay(wait);
//         strip.setPixelColor(strip.numPixels() - 1, 0);
//         strip.setPixelColor(0, 0);
//         strip.show();
//         delay(wait);
//     }
// }

// void OnOuter(uint32_t color)
// {
//     strip.setPixelColor(strip.numPixels() - 1, color);
//     strip.setPixelColor(0, color);
//     strip.show();
//     delay(3000);
// }

// void ClearLights()
// {
//     // for (int i = 0; i < (int)strip.numPixels(); i = i + 1)
//     // {
//     strip.fill(ledColors.black); //turn every pixel off
//     // }
//     // strip.show();
// }