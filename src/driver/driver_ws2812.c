#include "driver_ws2812.h"
#include "driver_usart1.h"
#include "driver_dma1.h"

static uint8_t *frame_buffer = NULL;
static uint8_t led_nums = 0;

static void driver_ws2812_set_rgb(rgb_t rgb, uint8_t *buffer);

void driver_ws2812_setup(uint8_t nums){
    led_nums = nums;
    frame_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (nums * 24 + 2));
    memset(frame_buffer, 0, sizeof(uint8_t) * (nums * 24 + 2));
}


static void driver_ws2812_set_rgb(rgb_t rgb, uint8_t *buffer){
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

void driver_ws2812_set_pixel_rgb(rgb_t rgb, uint8_t nums){
    driver_ws2812_set_rgb(rgb, &frame_buffer[2 + nums * 24]);
}

void driver_ws2812_show(){
    driver_spi_dma_transmit(frame_buffer, (led_nums*24+2));
}
