#include <stdio.h>
#include <math.h>

int check_prime(int a){
    int i;
    if(a<=0) return 0;
    for(i=2;i<=sqrt(a);i++){
        if(a%i == 0) return 0;
    }
    return 1;
}

int pow_two(int a){
    if(a==0) return 1;
    return 2*pow_two(a-1);
}

int main(){
    int i;
    for(i=1;i<=31;i++)
        if(check_prime(pow_two(i)-1))
            printf("%d\n",pow_two(i)-1);
    return 0;
}


//A better version (bit operation used)

// int check_prime(int a){
//     int i;
//     if(a<=0) return 0;
//     for(i=2;i<=sqrt(a);i++){
//         if(a%i == 0) return 0;
//     }
//     return 1;
// }

// int main(){
//     int i;
//     for(i=1;i<=31;i++)
//         if(check_prime((1<<i)-1))
//             printf("%d\n",(1<<i)-1);
//     return 0;
// }