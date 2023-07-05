#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint PIN_REDLED = 13;
const uint PIN_YELLOWLED = 14;
const uint PIN_GREENLED = 15;

int main() {
	bi_decl(bi_program_description("This is a program to blink 3 LEDs."));
	bi_decl(bi_1pin_with_name(PIN_REDLED, "External Red LED"));
	bi_decl(bi_1pin_with_name(PIN_YELLOWLED, "External Yellow LED"));
	bi_decl(bi_1pin_with_name(PIN_GREENLED, "External Green LED"));
	
	stdio_init_all();
	
	gpio_init(PIN_REDLED);
	gpio_set_dir(PIN_REDLED, GPIO_OUT);
	
	gpio_init(PIN_YELLOWLED);
	gpio_set_dir(PIN_YELLOWLED, GPIO_OUT);
	
	gpio_init(PIN_GREENLED);
	gpio_set_dir(PIN_GREENLED, GPIO_OUT);
	
	while(1) {
		
		gpio_put(PIN_REDLED,1);
		sleep_ms(2000);
		gpio_put(PIN_YELLOWLED,1);
		sleep_ms(1000);
		gpio_put(PIN_REDLED,0);
		gpio_put(PIN_YELLOWLED,0);
		gpio_put(PIN_GREENLED,1);
		sleep_ms(2000);
		gpio_put(PIN_GREENLED,0);
		gpio_put(PIN_YELLOWLED,1);
		
		sleep_ms(1000);
		gpio_put(PIN_YELLOWLED,0);
	
	}
}
