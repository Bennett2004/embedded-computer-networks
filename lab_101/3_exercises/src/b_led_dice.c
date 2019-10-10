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
	
	// init the random number generator
	init_random();
	
	// main loop
	while(1)
	{
		// get a random number between 1 and 6
		uint32_t rnd = (get_random_int() % 6) + 1;
		
		// make decisions based on the random number generated
		if (rnd == 1)
		{
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		if (rnd == 2)
		{
			toggle_gpio(led);
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		if (rnd == 3)
		{
			toggle_gpio(led);
			toggle_gpio(led);
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		if (rnd == 4)
		{
			toggle_gpio(led);
			toggle_gpio(led);
			toggle_gpio(led);
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		if (rnd == 5)
		{
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		if (rnd == 6)
		{
			toggle_gpio(led);
			HAL_Delay(1000);
		}
		
		
	}

}
