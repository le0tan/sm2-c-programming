//
// Created by Leo Tan on 20/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB7_4_H
#define SM2_C_PROGRAMMING_LAB7_4_H

#endif //SM2_C_PROGRAMMING_LAB7_4_H


#include <stdio.h>

int q4(){

    char buff[100];
    char search;
    char *ptr = buff;
    int count = 0;

    printf("Enter a string of not more than 10 characters: ");
    gets(buff);
    printf("Enter a search character: ");
    search = getchar();

    while(*ptr!='\0'){
        if(*ptr == search) count++;
        ptr++;
    }

    printf("In \"%s\", the number of occurrences of \'%c\' is %d\n",buff,search,count);

    return 0;
}