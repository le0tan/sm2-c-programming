#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265
#define X 0.75*PI

double compute(int n, double last){
	static double out = X;
	double ans = last*(-1)*X*X/(2*n-1)/(2*n-2);
	if(fabs(ans) < 1e-8){
		return out;
	} else {
		out += ans;
		return compute(n+1, ans);
	}
}


int main(){
	printf("%.5lf\n",compute(2,X));
	return 0;
}
