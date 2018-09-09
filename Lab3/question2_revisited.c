#include <stdio.h>


int main(){
	
	int a,b,original,sum=0;
	
	while(1){
		printf("\nEnter 0 to stop or enter a positive number smaller than 2147483647: ");
		scanf("%d%*c",&a);
		if(a==0) break;
		else{
			sum=0;
			original = a;
			while(a>0){
				b=a%10;
				a/=10;
				sum+=b;
				if(a>0) sum*=10;
			}
			if(original == sum) printf("%d is a palindrome.\n",original);
			else printf("%d is not a palindrome.\n",original);
		}
	}
	return 0;
}
