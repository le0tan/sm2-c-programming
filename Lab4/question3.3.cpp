#include <stdio.h>
#include <math.h>
#define E 2.7182818285
#define INI 2.0

double d(double x){
	return -sin(x)-3*pow(x,2.0);
}

double f(double x){
	return cos(x)-pow(x,3.0);
}

int main(){
	double ans;
	double last = 1.0;
	int iter = 0;
	double init = INI;
	ans = init;
	while(fabs(ans-last)>=0.00000001){
		last = ans;
		iter++;
		ans = ans - f(ans)/d(ans);
		printf("Answer after %d iteration(s) = %.7lf\n",iter,ans);
	}
	return 0;
}
