//
// Created by Leo Tan on 3/11/17.
//

#ifndef SM2_C_PROGRAMMING_LAB9_1_H
#define SM2_C_PROGRAMMING_LAB9_1_H

#endif //SM2_C_PROGRAMMING_LAB9_1_H

#include <stdio.h>
#include <string.h>


int q1(){
    int A[3][4] = { 1, 2,  3,  1,
                    0, 1, -5,  2,
                    6, 2,  0, -2} ;

    int B[4][3] = { 1,  0, -1,
                    0,  1,  1,
                    2,  3,  4,
                    0, -1,  0} ;
    int i,j,row1,col1,row2,col2;

    col1 = sizeof(A[0])/ sizeof(int);
    row1 = sizeof(A)/ sizeof(int)/col1;
    col2 = sizeof(B[0])/ sizeof(int);
    row2 = sizeof(B)/ sizeof(int)/col2;

    printf("     AXB    \n");
    printf("============\n");

    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            printf("%2d ",A[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose (AXB)\n");
    printf("===============\n");

    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            printf("%3d ",B[i][j]);
        }
        printf("\n");
    }

    return 0;
}