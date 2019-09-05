#include "driver_ws2812.h"
#include "driver_usart1.h"
void driver_ws2812_setup(){

}


void driver_ws2812_set_rgb(rgb_t rgb, uint8_t *buffer){
    CRGB color;
    color.red = (uint8_t)(rgb >> 16 & 0xFF);
    color.green = (uint8_t)(rgb >> 8 & 0xFF);
    color.blue = (uint8_t)(rgb & 0xFF);
    for(uint8_t i=0; i<8; i++){
        if(color.green >> i & 1){
            *(buffer + i) = WS2812_BIT1;
        }else{
            *(buffer + i) = WS2812_BIT0; 
        }

        if(color.red >> i & 1){
            *(buffer + 8 + i) = WS2812_BIT1;
        }else{
            *(buffer + 8 + i) = WS2812_BIT0;
        }

        if(color.blue >> i & 1){
            *(buffer + 16 + i) = WS2812_BIT1;
        }else{
            *(buffer + 16 + i) = WS2812_BIT0;
        }
    }
}