//
// Created by Leo Tan on 5/11/17.
//

#ifndef SM2_C_PROGRAMMING_LAB9_3_H
#define SM2_C_PROGRAMMING_LAB9_3_H

#endif //SM2_C_PROGRAMMING_LAB9_3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q3(){

    char a[25][16];
    int index[25],temp;
    int i,j,cnt=0;

    FILE * in;
    in = fopen("/Users/leo/Documents/_work/__summer 2017/___sm2/____c/Lab9/lab9/words.inf","r");

    if(in == NULL) exit(0);
    else{
        while(fscanf(in,"%s",a[cnt++])==1);
        cnt--;
        for(i=0;i<cnt;i++) index[i] = i;
        for(i=cnt;i>=0;i--){
            for(j=0;j<i;j++){
                if(strcmp(a[index[j]],a[index[j+1]])>0){
                    temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            }
        }
        printf("Sorted in lexicographical order\n");
        printf("===============================\n");

        for(i=0;i<cnt;i++) {
            printf("%6d.        ",i+1);
            printf("%s\n",a[index[i]]);
        }
    }

    fclose(in);

    return 0;
}