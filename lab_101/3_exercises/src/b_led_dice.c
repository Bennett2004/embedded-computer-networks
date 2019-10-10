/*
 * b_led_dice.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// map the led to gpio pins
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};
gpio_pin_t led4 = {PA_8,  GPIOA, GPIO_PIN_8};
gpio_pin_t led5 = {PA_15,  GPIOA, GPIO_PIN_15};
gpio_pin_t led6 = {PI_2,  GPIOI, GPIO_PIN_2};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	
	// init all the gpios for the dice dots
	init_gpio(led, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
	init_gpio(led6, OUTPUT);
	
	uint32_t rnd;
	
	// init the random number generator
	init_random();
	
	// main loop
	while(1)
	{
		// get a random number between 1 and 6
		rnd = (get_random_int() % 6) + 1;
		
		// make decisions based on the random number generated
		switch(rnd)
		{
			case 1:
				write_gpio(led, HIGH);
				break;
			case 2:
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				break;
			case 3:
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				break;
			case 4:
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led4, HIGH);
				break;
			case 5:
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led5, HIGH);
				break;
			case 6:
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led6, HIGH);
				break;
		}
		
		HAL_Delay(1000);
		
		// reset all leds
		write_gpio(led, LOW);
		write_gpio(led2, LOW);
		write_gpio(led3, LOW);
		write_gpio(led4, LOW);
		write_gpio(led5, LOW);
		write_gpio(led6, LOW);
		
		HAL_Delay(1000);
		
				
		
		
	}

}
