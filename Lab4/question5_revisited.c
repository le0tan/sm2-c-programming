#include <stdio.h>
#include <math.h>

#define SEED 47

//Change this line to integrate any function
#define f(x) (x)*(x)

//Return a random number in range [l,r]
double get_rand(double l, double r){
	return rand()/32767.0*fabs(r-l)+l;
}

double integral(int iter, double l, double r){
	int i, count = 0;
	double x,y;
	const double ymax = f(r);
	
	for(i=1;i<=iter;i++){
		x = get_rand(l,r);
		y = get_rand(0,ymax);
		if(y<=f(x)) count++;
	}
	return count*1.0/iter*fabs(r-l)*ymax;
}

int main(){
	srand(SEED);
	printf("%.5lf",integral(1000,2,5));	
	return 0;
}
