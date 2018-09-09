#include <stdio.h>


int main(){
	int n,i,k=1;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=2;i<=n/2;i++)
		if(!(n%i)) k+=i;
	if(k==n) printf("The number %d is a perfect number.\n",n);
	else printf("The number %d is not a perfect number.\n",n);
	return 0;
}