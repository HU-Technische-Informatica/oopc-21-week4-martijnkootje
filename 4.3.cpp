#include "hwlib.hpp"

int main( void ){
	auto swi1 = hwlib::target::pin_in_out( 3, 4 );
	auto swi2 = hwlib::target::pin_in_out( 3, 5 );
	
	swi1.direction_set_input();
	swi2.direction_set_input();
	
	auto led0 = hwlib::target::pin_in_out( 3, 3 );
	auto led1 = hwlib::target::pin_in_out( 3, 9 );
	auto led2 = hwlib::target::pin_in_out( 3, 10 );
	auto led3 = hwlib::target::pin_in_out( 3, 1 );
	auto led4 = hwlib::target::pin_in_out( 3, 21 );
	led0.direction_set_output();
	led1.direction_set_output();
	led2.direction_set_output();
	led3.direction_set_output();	
	led4.direction_set_output();	
	
	bool l1 = false;
	bool l2 = false;
	bool l3 = false;
	bool l4 = false;
	bool more = false;
	bool less = false;
	
   while(1){
	   swi1.refresh();
	   swi2.refresh();
		if(swi1.read() == 1){
			more = true;
		}
		if(swi2.read() == 1){
			less = true;
		}
	   
	   //meer lampjes
	   if(more == true){
		   if(l1 == true){
			   if(l2 == true){
				   if(l3 == true){
					   l4 = true;
				   }else{
					   l3 = true;
				   }
			   }else{
				   l2 = true;
			   }
		   }else{
			   l1 = true;
		   }
		  more = false;
	   }
	   
	   //minder lampjes
		if(less == true){
		   if(l4 == true){
				l4 = false;
		   }else{
			   if(l3 == true){
				   l3 = false;
			   }else{
				   if(l2 == true){
					   l2 = false;
				   }else{
					   if(l1 == true){
						   l1 = false;
					   }
				   }
			   }
		   }
		   less = false;
	   }  

		if(l1 == true){
			led0.write( 1 );
			led0.flush();
		}else{
			led0.write( 0 );
			led0.flush();
		}
		
		if(l2 == true){
			led1.write( 1 );
			led1.flush();
		}else{
			led1.write( 0 );
			led1.flush();
		}
		
		if(l3 == true){
			led2.write( 1 );
			led2.flush();
		}else{
			led2.write( 0 );
			led2.flush();
		}
		
		if(l4 == true){
			led3.write( 1 );
			led3.flush();
		}else{
			led3.write( 0 );
			led3.flush();
		}
		hwlib::wait_ms( 150 );
}
}