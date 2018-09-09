//
// Created by Leo Tan on 20/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB7_3_H
#define SM2_C_PROGRAMMING_LAB7_3_H

#endif //SM2_C_PROGRAMMING_LAB7_3_H

#include <stdio.h>

int validate(char* id){
    int weight[]={2,7,6,5,4,3,2};
    char check[]={'A','B','C','D','E','F','G','H','I','Z','J'};
    int i,sum=0,ans;
    for(i=0;i<7;i++)
        sum+=(int)(id[i]-'0') * weight[i];
    ans = 11 - (sum % 11);
    if(check[ans-1]==id[7]) return 1;
    else return 0;
}

int q3(){

    FILE* in = fopen("/Users/leo/CLionProjects/SM2_C_Programming/IDENTITY.INF","r");
    char id[20];
    int count = 0;

    puts("Validation of Identity Card Number");
    puts("==================================");

    while(fgets(id,9,in) != NULL){
        fscanf(in,"%*c%*c");
        printf("%2d.    %s        ",++count,id);
        if(validate(id)) puts("Valid");
        else puts("==> Invalid");
    };

    return 0;
}