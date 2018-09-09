#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    srand(47);
    int i,cnt=0;
    double x,y,f1,f2,area;
    for(i=1;i<=10000;i++){
        x = rand()*1.0/RAND_MAX*3-2.0;
        y = rand()*1.0/RAND_MAX*7;
        printf("x = %.2lf, y = %.2lf\n",x,y);
        f1 = 7.0-x*x;
        f2 = exp(x);
        printf("f1 = %.2lf, f2 = %.2lf\n",f1,f2);
        if(y>=f2 && y<=f1) cnt++;
    }
    area = 3.0*7.0*cnt/10000;
    printf("%.5lf",area);
    return 0;
}