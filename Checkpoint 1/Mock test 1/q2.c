#include <stdio.h>
#include <math.h>
#define tor 0.0001

int main(void){
    double term=-1.0,sum=0.0;
    int cnt=0;
    while (fabs(term*0.5/++cnt)>=tor) {
        term = term*0.5*(-1);
        sum+=term/cnt;
    }
    printf("%.4lf\n",sum);
    return 0;
}