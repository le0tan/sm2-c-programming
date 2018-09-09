#include <stdio.h>
#include <math.h>

#define iter 10000000

#define SEED 47

int roll(){
	double a = rand()/32767.0;
	if(a<0.2) return 1;
	if(a>=0.2 && a<0.4) return 2;
	if(a>=0.4 && a<0.45) return 3;
	if(a>=0.45 && a<0.5) return 4;
	if(a>=0.5 && a<0.8) return 5;
	if(a>=0.8) return 6;
}

int main(){
	srand(SEED);
	int i;
	const int bet = 2;
	int expected_return = 0, Bet = 0;
	for(i=1;i<=iter;i++){
		switch(roll()){
			case 1:
				Bet += bet;
				break;
			case 2:
				Bet += bet;
				break;
			case 3:
				Bet += bet;
				expected_return += bet;
				break;
			case 4:
				Bet += bet;
				expected_return += bet;
				break;
			case 5:
				Bet += bet;
				expected_return += bet+1;
				break;
			case 6:
				Bet += bet;
				expected_return += bet+2;
				break;
		}
	}
	printf("%d %d\n",Bet,expected_return);
	printf("House advantage = %.2f",(Bet-expected_return)*1.0/Bet*100);
	return 0;
}
