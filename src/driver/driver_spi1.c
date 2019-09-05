#include "driver_spi1.h"

/* 
 * STM32F103 Blue pill SPI pinout
 * 
 * SPI1--NSS   PA4
 * SPI1--SCK   PA5 
 * SPI1--MISO  PA6
 * SPI1--MOSI  PA7
 * 
 */
void driver_spi1_setup(){
    rcc_periph_clock_enable(RCC_SPI1);

	/* Configure GPIOs: SS=PA4, SCK=PA5, MISO=PA6 and MOSI=PA7
	 * For now ignore the SS pin so we can use it to time the ISRs
	 */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
            GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, /* GPIO4 | */
            								GPIO5 |
                                            GPIO7 );

	gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT,
			GPIO6);

	/* Reset SPI, SPI_CR1 register cleared, SPI is disabled */
	spi_reset(SPI1);


	/* Set up SPI in Master mode with:
	 * Clock baud rate: 1/8 of peripheral clock frequency
	 * Clock polarity: Idle High
	 * Clock phase: Data valid on 2nd clock pulse
	 * Data frame format: 8-bit or 16-bit
	 * Frame format: MSB First
	 */

	spi_init_master(
			SPI1, 
			SPI_CR1_BAUDRATE_FPCLK_DIV_8, 
			SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_2, 
			SPI_CR1_DFF_8BIT, 
			SPI_CR1_MSBFIRST);


	/* Enable SPI1 periph. */
	spi_enable(SPI1);
}