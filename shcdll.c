uint64_t volatile __old_time;
uint64_t volatile __new_time;
uint64_t volatile __millis=0;

void init_timer2(void){
	TCCR2B |=(1<<CS22); 
	TCCR2A|=(1<<WGM21);
	TIMSK2 |=(1<<OCIE2A); 
	TIFR2 |=(1<<OCF2A); 
	TCNT2=0; 
	OCR2A=249; 

}


   new_time=__millis;
   if(new_time-old_time>500){
	ref=300;
	
   }if(new_time-old_time>1000){
	ref=700;
	old_time=new_time;
   }




ISR (TIMER2_COMPA_vect){ 
	__millis++;
}
