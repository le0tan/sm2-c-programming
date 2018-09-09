#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int check_prime(int n){
	int i;
	int flag = TRUE;
	for(i=2;i<=sqrt(n);i++){
		if(n%i == 0){
			flag = FALSE;
			break;
		}
	}
	if(flag) return 1;
	return 0;
}


int main(){
	int a;
	printf("Enter an integer larger than 2 and less than 2147483647: ");
	if(!scanf("%d",&a)) {
		printf("Invalid input.\n");
		getchar();
	} else if(a>2 && a<2147483647)
				if(check_prime(a)) printf("%d is a prime number\n\n",a);
				else printf("%d is not a prime number\n",a);
			else printf("Invalid input.\n");
	return 0;
}
