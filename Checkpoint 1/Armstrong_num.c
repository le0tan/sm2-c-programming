//Check the input is an Armstrong Number or not
//An armstrong number is a number equals to the
//sum of the cubic of each digit.
//e.g. 153=1^3+5^3+3^3 so it's an Armstrong Number

#include <stdio.h>


int main(){
	int a,b,c,sum=0;

	scanf("%d",&a);
	c=a;
	while(a>0){
		b=a%10;
		a/=10;
		sum+=b*b*b;
	}
	if(sum==c) printf("yes");
	else printf("no");

	return 0;
}