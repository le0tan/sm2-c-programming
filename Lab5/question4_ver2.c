#include <stdio.h>


int main(void){
	
	char a;
	int flag = 1;
	
	printf("Enter message: ");
	do{
		scanf("%c",&a);
		switch(a){
			case 'a':
				a = '!';
				break;
			case 'e':
				a = '$';
				break;
			case 'i':
				a = '#';
				break;
			case 'o':
				a = '*';
				break;
			case 'u':
				a = '&';
				break;
		}
		if(flag){
			printf("Encrypted message: ");
			flag = 0;
		}
		printf("%c",a);
	} while(a != '\n');
	return 0;
}
