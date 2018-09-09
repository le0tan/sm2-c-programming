#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SEED 129387
#define ROUND 1000000

int dice(){
	int ans = rand()%100;
	if(ans<=20) return 1;
	else if(ans>20&&ans<=40) return 2;
	else if(ans>40&&ans<=45) return 3;
	else if(ans>45&&ans<=50) return 4;
	else if(ans>50&&ans<=80) return 5;
	else return 6;
}

int main(){
	srand(SEED);
	int i,bet=0,exb=0;
	for(i=1;i<=ROUND;i++){
		bet+=2; exb+=2;
		switch(dice()){
			case 1:{
				exb-=2;
				break;
			}
			case 2:{
				exb-=2;
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				exb+=1;
				break;
			}
			case 6:{
				exb+=2;
				break;
			}
			default: break;
		}
	}
	double out = (double)(bet-exb)/(double)bet;
	printf("The House Advantage = %%lf \n",out*100);
	return 0;
}
