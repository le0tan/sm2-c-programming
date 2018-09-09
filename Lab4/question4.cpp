#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEED 456

int main(){
	srand(SEED);
	int i;
	for(i=1;i<=20;i++){
		double rad = rand()/65535.0;
		double ans = rad - trunc(rad);
		printf("Random number %d = %lf\n",i,ans*6.31-2.55);
	}
		
	return 0;
}
