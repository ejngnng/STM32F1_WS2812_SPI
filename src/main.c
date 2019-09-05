#include "driver/driver_spi1.h"
#include "driver/driver_usart1.h"
#include "driver/driver_ws2812.h"
#include "driver/driver_usart1.h"
#include "driver/driver_dma1.h"
#include "color/color.h"
#include "driver/driver_tick.h"

uint32_t timeout = 50000;
/*
 * Main program: Device initialization etc.
 */
int main(void) {

	rcc_clock_setup_in_hse_8mhz_out_72mhz();	// Use this for "blue pill"
	driver_tick_setup();
	driver_usart1_setup();
	driver_spi1_setup();
	driver_dma1_setup();
	driver_ws2812_setup(3);
	printf("setup done\n");
	while(1){
		// spi_send(SPI1, 0x0);
		// spi_send(SPI1, 0x0);
		// driver_ws2812_set_rgb(RGB_Blue, buffer);
		// for(uint8_t i=0; i<24; i++){
		// 	spi_send(SPI1, buffer[i]);
		// }
		// printf("start while 1 set LED Red\n");
		// driver_ws2812_set_rgb(RGB_Red, &buffer[2]);
		// // driver_spi_dma_transceive(buffer, 24+2);
		// driver_spi_dma_transmit(buffer, 26);
		// delay_ms(1000);
		// printf("start while 1 set LED Green\n");
		// driver_ws2812_set_rgb(RGB_Green, &buffer[2]);
		// driver_spi_dma_transmit(buffer, 26);
		// delay_ms(1000);
		// printf("start while 1 set LED Blue\n");
		// driver_ws2812_set_rgb(RGB_Blue, &buffer[2]);
		// driver_spi_dma_transmit(buffer, 26);
		// delay_ms(1000);
		// printf("start while 1 set LED Yello\n");
		// driver_ws2812_set_rgb(RGB_Yellow, &buffer[2]);
		// driver_spi_dma_transmit(buffer, 26);
		// printf("==========================================\n");
		// delay_ms(1000);
		driver_ws2812_set_pixel_rgb(RGB_Red, 0);
		driver_ws2812_set_pixel_rgb(RGB_Green, 1);
		driver_ws2812_set_pixel_rgb(RGB_Brown, 2);
		driver_ws2812_show();
		delay_ms(500);
		for(uint8_t i=0; i<2; i++){
			driver_ws2812_set_pixel_rgb(RGB_Black, i);
		}
		driver_ws2812_show();
		delay_ms(500);
	}
	return 0;
}