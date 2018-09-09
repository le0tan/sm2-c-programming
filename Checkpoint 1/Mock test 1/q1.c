#include <stdio.h>


int main(void){
    int flag = 0;
    char a;
    while(scanf("%c",&a)){
        if(a==' ')
            if(flag) continue;
            else{
                flag = 1;
                printf(" ");
            }
        else{
            if(flag) flag = 0;
            if(a=='\n') {
                printf("\n");
                break;
            }
            else printf("%c",a);
        }
    }
    return 0;
}