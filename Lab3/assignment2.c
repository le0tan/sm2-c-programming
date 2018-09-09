#include <stdio.h>

int power(int n){
	if(n==0) return 1;
	else return 10*power(n-1);
}

int check(int n){
	int digits[20];
	int cnt=0, pal=0, original=n, i;
	while(n>0){
		digits[++cnt] = n%10;
		n /= 10;
	}
	for(i=1;i<=cnt;i++)
		pal += digits[i] * power(cnt-i);
	//printf("%d\n",pal);
	if(pal == original) return 1;
	else return 0;
}

int main(){
	int n=1;
	while(n){
		printf("Enter 0 to stop or enter a positive number smaller than 2147483647: ");
		scanf("%d",&n);
		if(!n) continue;
		if(check(n)) printf("%d is a palindrome.\n",n);
		else printf("%d is not a palindrome.\n",n);
	}
	return 0;
}