#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define L 2
#define R 5
#define SEED 47

const int iter = 1000000;

double range_rand(double l,double r){
	//Generate random number in range(0,1)
	double rad = rand()/511.0;
	double ans = rad - trunc(rad);
	return l+ans*(r-l);
}

double f(double x){
	return x*x;
}

int main(){
	srand(SEED);
	int i,hit=0;
	for(i=1;i<=iter;i++){
		//printf("%f\n",range_rand(2,5));
		double x = range_rand(L,R);
		double y = range_rand(0,f(R));
		if(y<=f(x)) {
			hit++;
			//printf("yes\n");
		}
		//printf("%d >> x = %f, y = %f\n",i,x,y);
	}
	double area = (double)hit/iter * (R-L) * f(R);
	printf("%f",area);
}

