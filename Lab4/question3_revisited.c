#include <stdio.h>
#include <math.h>

#define tor 0.0001
#define iter 10

//Note that change f to #define f(x) (x)*(x)-37 may cause unexpected behavior
double f(double x){
	return x*x-37;
}

int main(){
	double x0 = 0.5, x1 = 2.1, temp, last = x1+1;
	int cnt=0;
	while(fabs(x1-last)>=tor && ++cnt<=iter){
		last = x1;
		double g = (f(x1)-f(x0))/(x1-x0);
		temp = x1;
		x1 = x1 - f(x1)/g;
		x0 = temp;
		printf("x1 = %.5lf, x0 = %.5lf, f(x) = %.5lf\n",x1,x0,f(x1));
	}
	printf("%.5lf",x0);
	return 0;
}
