//
// Created by Leo Tan on 20/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB7_2_H
#define SM2_C_PROGRAMMING_LAB7_2_H

#endif //SM2_C_PROGRAMMING_LAB7_2_H

#include <stdio.h>

float findMax(float a1, float a2, float a3, float a4){
    float temp = a1;
    if(a2>temp) temp = a2;
    if(a3>temp) temp = a3;
    if(a4>temp) temp = a4;
    return temp;
}

float computeAverage(float* start, float* end){
    float * ptr = start;
    float accumulator = 0.0;
    int count = 0;
    while(ptr <= end){
        accumulator += *ptr;
        ptr++;  count++;
    }
    return accumulator/count;
}

int q2(){

    FILE* in = fopen("/Users/leo/CLionProjects/SM2_C_Programming/READING.INF","r");
    float a1,a2,a3,a4;
    float max[40];
    int cnt = 0;

    printf("Day         Highest Temperature\n");
    printf("-------------------------------\n");
    while (fscanf(in,"%f%f%f%f",&a1,&a2,&a3,&a4)==4){
        max[++cnt] = findMax(a1,a2,a3,a4);
        printf("%2d.               %.2f\n",cnt,max[cnt]);
    }
    printf("The average of the highest temperature in the first five days is %.2f\n", computeAverage(max+1,max+5));
    printf("The average of the highest temperature in the last five days is %.2f\n",computeAverage(max+cnt-4,max+cnt));

    fclose(in);

    return 0;
}