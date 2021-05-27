#include "hwlib.hpp"
int main( void ){	
	auto led0 = hwlib::target::pin_in_out( 0, 10 );
	auto led1 = hwlib::target::pin_in_out( 0, 11 );
	auto led2 = hwlib::target::pin_in_out( 0, 12 );
	auto led3 = hwlib::target::pin_in_out( 0, 13 );
	
	led0.direction_set_output();
	led0.direction_flush();
	
	led1.direction_set_output();
	led1.direction_flush();
	
	led2.direction_set_output();
	led2.direction_flush();
	
	led3.direction_set_output();
	led3.direction_flush();
   while(1){
		led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		led0.write( 1 );
		led0.flush();
		led1.write( 1 );
		led1.flush();
		hwlib::wait_ms( 1200 );
		led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		
		led1.write( 1 );
		led1.flush();
		led2.write( 1 );
		led2.flush();
		hwlib::wait_ms( 1200 );
				led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		
		led2.write( 1 );
		led2.flush();
		led3.write( 1 );
		led3.flush();
		hwlib::wait_ms( 1200 );
		led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		
		led1.write( 1 );
		led1.flush();
		led2.write( 1 );
		led2.flush();
		hwlib::wait_ms( 1200 );
		led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		
		led0.write( 1 );
		led0.flush();
		led1.write( 1 );
		led1.flush();
		hwlib::wait_ms( 1200 );
		led0.write( 0 );
		led0.flush();
		led1.write( 0 );
		led1.flush();
		led2.write( 0 );
		led2.flush();
		led3.write( 0 );
		led3.flush();
		hwlib::wait_ms( 200 );
}
}
