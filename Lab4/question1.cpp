#include <stdio.h>
#include <cmath>
#include <windows.h>
#define PI 3.14159265

int main(){
	double ans = 0.0;
	double last = 1.0;
	double term = 2.0;
	int iter = 1;
	double t;
	while(fabs(last - ans)>=0.00000001){
		iter++; last = ans;
		ans += term;
		term = term * (-1) * PI * PI / (2*iter -3) / (2*iter -2);
		printf("Term %d: %.7lf\n", iter, term);
		printf("Deviation %d = %.7lf\n",iter,fabs(last - ans));
		printf("Ans %d = %.7lf\n\n",iter,ans);
		Sleep(500);
	}
	return 0;
}
