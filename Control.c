/* 
 * File:   Control.c
 * Author: Javier Vazquez
 *
 * Created on 19 de mayo de 2017, 02:04 AM
 */
#include <18F4550.h>

#device adc=8


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#fuses HS, NOWDT, XT
#fuses NOPROTECT, BROWNOUT, PUT, NOLVP
#use delay(clock=4MHz)

void servo0(){
    int i;
for(i=0;i<70;i++){
            output_high(PIN_B0);
            delay_us(160);
            output_low(PIN_B0);
            delay_us(9840);
        }
}
void servo90(){
    int i;
for(i=0;i<70;i++){
            output_high(PIN_B0);
            delay_us(405);
            output_low(PIN_B0);
            delay_us(9595);
        }
}
void servo180(){
    int i;
for(i=0;i<70;i++){
            output_high(PIN_B0);
            delay_us(800);
            output_low(PIN_B0);
            delay_us(9200);
        }
}
void servo45(){
    int i;
for(i=0;i<70;i++){
            output_high(PIN_B0);
            delay_us(273);
            output_low(PIN_B0);
            delay_us(9728);
        }
}
void servo135(){
    int i;
for(i=0;i<70;i++){
            output_high(PIN_B0);
            delay_us(510);
            output_low(PIN_B0);
            delay_us(9490);
        }
}
/* 
 *
 */
int j=1;
int i;
void main() {
    long count;
    setup_timer_0(T0_EXT_H_TO_L|RTCC_DIV_1);
    set_timer0(0);

    output_low(PIN_B0);
    delay_ms(500);
    
     output_low(PIN_B2);
while(1){ 
    set_timer0(0);
    count =0;
    servo90();
    for (i = 0; i<50; i++){
        output_high(PIN_B2);
    count = get_timer0();
    delay_ms(10);
    }
    output_low(PIN_B2);    
       if (count > 2 || count == 0){
            if (count > 10){
                set_timer0(0);
                count =0;
            }
            else{
                servo90();
                output_low(PIN_B2);
                delay_ms(1000);
            }
        }

    
        
        if (count % 2 == 0){
            //output_high(PIN_B2);
            servo135();
            
            delay_ms(2000);
            set_timer0(0);
                count =0;

        }
        else{
            //output_high(PIN_B2);
            servo45();  
            delay_ms(2000);
            set_timer0(0);
                count =0;
        }
    
    }
}
