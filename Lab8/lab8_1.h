//
// Created by Leo Tan on 27/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB8_1_H
#define SM2_C_PROGRAMMING_LAB8_1_H

#endif //SM2_C_PROGRAMMING_LAB8_1_H


#include <stdio.h>

float computeThreshold (int  image[8][8])
{
    int i,j,max=image[0][0],min=image[0][0];
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            if(image[i][j]>max) max = image[i][j];
            if(image[i][j]<min) min = image[i][j];
        }
    return (float)(max+min)/2;
}

void convertToBinaryImage (int image[8][8], float threshold)
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            if(image[i][j]>threshold) image[i][j] = 1;
            else image[i][j] = 0;
        }
}

int q1()
{
    int i,j,threshold;
    const char block = 219;
    int letter[8][8] =
            {
                    6, 6, 6, 6, 6, 6, 6, 6,
                    6, 2, 2, 2, 2, 2, 2, 6,
                    6, 3, 1, 0, 1, 1, 2, 7,
                    6, 6, 5, 0, 1, 5, 6, 6,
                    6, 6, 5, 3, 3, 5, 6, 7,
                    7, 6, 5, 3, 2, 6, 6, 7,
                    7, 6, 6, 2, 2, 5, 6, 7,
                    7, 7, 7, 7, 7, 7, 7, 7
            };
    threshold = computeThreshold(letter);
    convertToBinaryImage(letter,threshold);
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(letter[i][j]) printf("%c",block);
            else printf(" ");
        }
        printf("\n");
    }



    return 0;
}



