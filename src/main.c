#include "driver/driver_spi1.h"
#include "driver/driver_usart1.h"
#include "driver/driver_ws2812.h"
#include "driver/driver_usart1.h"
#include "color/color.h"



void convert_to_rgb(uint8_t r, uint8_t g, uint8_t b){

	// G
	for(uint8_t i=0; i<8; i++){
		if(g >> i & 1){
			spi_send(SPI1, BIT1);
		}else{
			spi_send(SPI1, BIT0);
		}
	}

	// R
	for(uint8_t i=0; i<8; i++){
		if(r >> i & 1){
			spi_send(SPI1, BIT1);
		}else{
			spi_send(SPI1, BIT0);
		}
	}

	// B
	for(uint8_t i=0; i<8; i++){
		if(b >> i & 1){
			spi_send(SPI1, BIT1);
		}else{
			spi_send(SPI1, BIT0);
		}
	}

}

uint32_t timeout = 50000;
/*
 * Main program: Device initialization etc.
 */
int main(void) {

	rcc_clock_setup_in_hse_8mhz_out_72mhz();	// Use this for "blue pill"
	driver_usart1_setup();
	driver_spi1_setup();
	uint8_t buffer[24] = {0};
	while(1){
		spi_send(SPI1, 0x0);
		spi_send(SPI1, 0x0);
		driver_ws2812_set_rgb(RGB_Blue, buffer);
		for(uint8_t i=0; i<24; i++){
			spi_send(SPI1, buffer[i]);
		}
	}
	return 0;
}