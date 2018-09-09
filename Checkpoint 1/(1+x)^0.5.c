#include <stdio.h>
#include <math.h>

#define tolerance 0.00001
#define rounds 10000
#define x 1

int main(){
    int cnt = 1;
    double term=.5,sum=1.5;
    while((term>=tolerance || term<=-tolerance)&&cnt<=rounds){
        cnt++;
        term=term*(-1.0)*(2*cnt-3)/(2*cnt)*x;
        sum+=term;
    }
    printf("%lf\n",sum);
    return 0;
}