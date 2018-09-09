#include <stdio.h>

int main(void){
	//Declaration
	char mess[256],en[256],temp;
	int cnt=0,i;
	//Read-in
	while(1){
		scanf("%c",&temp);
		if(temp == '\n') break;
		else mess[cnt++] = temp;
	}
	//Process
	for(i=0;i<cnt;i++){
		switch(mess[i]){
			case 'a':
				en[i] = '!';
				break;
			case 'e':
				en[i] = '$';
				break;
			case 'i':
				en[i] = '#';
				break;
			case 'o':
				en[i] = '*';
				break;
			case 'u':
				en[i] = '&';
				break;
			default:
				en[i] = mess[i];
				break;
		}
	}
	en[cnt] = '\n';
	//Print-out
	for(i=0;i<cnt;i++) printf("%c",en[i]);
	return 0;
}
