//
// Created by Leo Tan on 20/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB7_1_H
#define SM2_C_PROGRAMMING_LAB7_1_H

#endif //SM2_C_PROGRAMMING_LAB7_1_H

#include <stdio.h>
#include <stdlib.h>


int gcd(const int a,const int b){
    if(a%b == 0) return b;
    return gcd(b,a%b);
}

int lcm(const int a,const int b){
    return a*b/gcd(a,b);
}

int q1(){
    int a,b,flag = 1;
    while(flag){
        printf("Enter any two positive integers: ");
        scanf("%d %d",&a,&b);
        if(a == 0){
            flag = 0;
            break;
        }
        printf("LCM of %d and %d is %d\n",a,b,lcm(a,b));
    }
    return 0;
}