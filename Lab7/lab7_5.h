//
// Created by Leo Tan on 20/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB7_5_H
#define SM2_C_PROGRAMMING_LAB7_5_H

#endif //SM2_C_PROGRAMMING_LAB7_5_H


#include <stdio.h>
#include <string.h>

void process (char*);

int q5()
{
    char string[100];

    printf("Enter a string of not more than 99 characters: ");
    gets(string);
    printf ("The length of string before packing is %d\n", strlen (&string[0]) );
    process (string);
    printf("Packed String: %s\n",string);
    printf ("The length of string after packing is %d\n", strlen (&string[0]) );

    return 0;
}

void process (char s[])
{
    char *ptr = s;
    char *read = s;
    while(*read != '\0'){
        if((*read>='a' && *read<='z')||(*read>='A' && *read<='Z')) {
            *ptr = *read;
            ptr++;
            read++;
        }
        else {
            read++;
        }
    }
    *ptr++ = '\0';
    return;
}