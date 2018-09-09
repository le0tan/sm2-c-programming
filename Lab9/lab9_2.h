//
// Created by Leo Tan on 3/11/17.
//

#ifndef SM2_C_PROGRAMMING_LAB9_2_H
#define SM2_C_PROGRAMMING_LAB9_2_H

#endif //SM2_C_PROGRAMMING_LAB9_2_H

#include <stdio.h>
#include <string.h>

int check(char* a, int len){
    char *head = a, *tail = a+len-1;
    while(head<=tail){
        if(*head != *tail) return 0;
        else{
            head++; tail--;
        }
    }
    return 1;
}

int q2()
{
    char a[21];

    do{
        printf("Enter a word of not more than 20 characters: ");
        scanf("%c",a);
        if(a[0] == '\n') break;
        else{
            scanf("%s",a+1);
            if(check(a,strlen(a))) printf("\"%s\" is a palindrome.\n",a);
            else printf("\"%s\" is not a palindrome.\n",a);
            getchar();
        }
    }while(1);
    return 0;
}