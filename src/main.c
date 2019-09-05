#include "driver/driver_spi1.h"
#include "driver/driver_usart1.h"
#include "driver/driver_ws2812.h"
#include "driver/driver_usart1.h"
#include "driver/driver_dma1.h"
#include "color/color.h"
#include "driver/driver_tick.h"

#define LED_NUMS	3 // 3 leds
/*
 * Main program: Device initialization etc.
 */
int main(void) {

	rcc_clock_setup_in_hse_8mhz_out_72mhz();	// Use this for "blue pill"
	driver_tick_setup();
	driver_usart1_setup();
	driver_spi1_setup();
	driver_dma1_setup();
	driver_ws2812_setup(LED_NUMS);
	#if (DEBUG == 1)
	printf("setup done\n");
	#endif
	while(1){
		driver_ws2812_set_pixel_rgb(RGB_Red, 0);
		driver_ws2812_set_pixel_rgb(RGB_Green, 1);
		driver_ws2812_set_pixel_rgb(RGB_Blue, 2);
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