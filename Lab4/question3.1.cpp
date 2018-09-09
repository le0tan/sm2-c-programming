#include <stdio.h>
#include <math.h>
#define E 2.7182818285
#define INI 0.25

double f(double x){
    return pow(E,2*x)-x-6;
}

double G(double x0,double x1){
    return (f(x1)-f(x0))/(x1-x0);
}

int main(){
    double x0=0.25,x1=1.2,temp=2333.0,last=233.0;
    while(fabs(last-temp)>=0.00000001){
        x0 = G(x1,x0);
        temp = x1;
        x1 = x1-(f(x1)/x0);
        x0 = temp;
        printf("%lf\n",temp);
    }
    return 0;
}

//#include <stdio.h>
//#include <math.h>
//#define E 2.7182818285
//#define INI 0.25
//
//double d(double x){
//    return 2*pow(E,2*x)-1;
//}
//
//double f(double x){
//    return pow(E,2*x)-x-6;
//}
//
//int main(){
//    double ans;
//    double last = 1.0;
//    int iter = 0;
//    double init = INI;
//    ans = init;
//    while(fabs(ans-last)>=0.00000001){
//        last = ans;
//        iter++;
//        ans = ans - f(ans)/d(ans);
//        printf("Answer after %d iteration(s) = %.7lf\n",iter,ans);
//    }
//    return 0;
//}
//