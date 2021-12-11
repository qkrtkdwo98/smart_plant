#include <stdio.h>
#include <wiringPi.h>
#include <errno.h>

#define A1 0
#define A2 1
#define B1 2
#define B2 3
#define ENA 4
#define ENB 5

#define S1 27
#define S2 28
#define S3 29
#define LED 7

#define Sen 6

#define mode1 1
#define mode2 2
#define mode3 3

int mode =0;

void interrupt1(void){
	printf("check1");
	mode = mode1;
}

void interrupt2(void){
	mode = mode2;
}

void interrupt3(void){
	mode = mode3;
}

int main(void)
{
	if(wiringPiSetup()==-1)
		return -1;

	pinMode (A1, OUTPUT);
	pinMode (A2, OUTPUT);
	pinMode (B1, OUTPUT);
	pinMode (B2, OUTPUT);
	pinMode (ENA, OUTPUT);
	pinMode (ENB, OUTPUT);
	pinMode (S1, INPUT);
	pinMode (S2, INPUT);
	pinMode (S3, INPUT);
	pinMode (LED, OUTPUT);
	pinMode (Sen, INPUT);
	digitalWrite(ENA,HIGH);
	digitalWrite(ENB,HIGH);

	if(wiringPiISR(S1, INT_EDGE_FALLING, &interrupt1)<0){
		return 1;		
	}
	if(wiringPiISR(S2, INT_EDGE_FALLING, &interrupt2)<0){
		return 1;		
	}
	if(wiringPiISR(S3, INT_EDGE_FALLING, &interrupt3)<0){
		return 1;		
	}
	while(1){
		if(digitalRead(Sen)==1)//moisture low
		{
			digitalWrite(LED, HIGH);
		}
		if(digitalRead(Sen)==0)//moisture high
		{
			digitalWrite(LED, LOW);
		}
		
		if(mode==mode1){

			//printf("mode1");
			for(int a=0;a<10;a++)
			{
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
		
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
			
			}
			delay(1000);
		}
		if(mode==mode2){
			
			//printf("mode2");
			for(int a=0;a<10;a++)
			{
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
		
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
			
			}
			delay(5000);
		}
		if(mode==mode3){
			
			//printf("mode3");
			for(int a=0;a<10;a++)
			{
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
		
				digitalWrite(A1,LOW);
				digitalWrite(A2,HIGH);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,LOW);
				digitalWrite(B2,HIGH);
				delay(10);
		
				digitalWrite(A1,HIGH);
				digitalWrite(A2,LOW);
				digitalWrite(B1,HIGH);
				digitalWrite(B2,LOW);
				delay(10);
			
			}
			delay(10000);
		}
		//delay(100);
		
	}
	return 0;
}
