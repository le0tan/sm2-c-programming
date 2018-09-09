#include <stdio.h>
#include <stdlib.h>
#define SEED 47
#define ITER 50000

int toss(){
	int rad = rand()%100;
	if(rad>=0&&rad<25) return 1;
	else if(rad>=25&&rad<50) return 2;
	else if(rad>=50&&rad<75) return 3;
	else return 4;
}

int main(){
	srand(SEED);
	int i,cas=0,pat=0;
	//I'm assuming that you would buy the insurance every time you toss the dice.
	for(i=1;i<=ITER;i++){
		switch(toss()){
			case 1:{
				pat-=2; cas+=2;
				break;
			}
			case 2:{
				pat-=1; cas+=1;
				break;
			}
			case 3:{
				pat+=1; cas-=1;
				break;
			}
			case 4:{
				pat-=3; cas+=3;
				break;
			}
		}
	}
	if(cas>pat) printf("The insurance scheme benefits the casino.");
	else printf("The insurance scheme benefits the patron.");
	return 0;
}
