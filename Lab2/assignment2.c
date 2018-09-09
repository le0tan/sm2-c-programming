#include <stdio.h>
#define INF 2147483647
#define TRUE 1
#define FALSE 0

int main(){
	int flag=TRUE;
	int a;
	char b;
	char buff[255];								//buffer var
	while(flag){
		printf("Enter a positive integer not greater than 2147483647\n");
		if(!scanf("%d",&a)) {
			printf("Data is not accepted. Please obey the instruction.\n");
			scanf("%s",buff);					//buffer input
		}
		else if(a<0||a>INF) printf("Data is not accepted. Please obey the instruction.\n");
		else {
			if(a%2 == 0) printf("%d is even.\n",a);
			else printf("%d is odd.\n",a);
		}
		printf("Enter y or Y if you want to continue: ");
		getchar();								//the same as scanf("*%c"), read in the '\n'
		scanf("%c",&b);
		if(b=='y'||b=='Y'){
			printf("\n");
		} else {
			flag = FALSE;
		}
	}
	return 0;
}
