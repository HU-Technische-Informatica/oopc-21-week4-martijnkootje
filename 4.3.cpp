#include "hwlib.hpp"

void switches(hwlib::pin_in_out & swi1, hwlib::pin_in_out & swi2, bool &more, bool &less){
	swi1.refresh();
	swi2.refresh();
	if(swi1.read() == 1){
		more = true;
	}
	if(swi2.read() == 1){
		less = true;
	}
}

int main( void ){
	auto swi1 = hwlib::target::pin_in_out( 2, 17 );
	auto swi2 = hwlib::target::pin_in_out( 2, 15 );
	swi1.direction_set_input();
	swi2.direction_set_input();
	
	auto led0 = hwlib::target::pin_in_out( 3, 1 );
	auto led1 = hwlib::target::pin_in_out( 3, 3 );
	auto led2 = hwlib::target::pin_in_out( 3, 9 );
	auto led3 = hwlib::target::pin_in_out( 3, 10 );
	led0.direction_set_output();
	led1.direction_set_output();
	led2.direction_set_output();
	led3.direction_set_output();	
	
	bool l1 = false;
	bool l2 = true;
	bool l3 = false;
	bool l4 = true;
	bool more = false;
	bool less = false;
	
   while(1){
	   switches(swi1, swi2, more, less);
	   
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

	led0.write(l1);
	led1.write(l2);
	led2.write(l3);
	led3.write(l4);
	hwlib::wait_ms( 150 );
}
}
