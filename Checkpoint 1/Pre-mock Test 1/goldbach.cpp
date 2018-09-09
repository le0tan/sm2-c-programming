#include <stdio.h>
#include <math.h>

int check_prime(int x){
	int i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0) return 0;
	}
	return 1;
}

int main(){
	int x,i,cnt=0;
	printf("Enter an even number which is greater than 2: ");
	scanf("%d",&x);
	if(x%2!=0||x<=2)
		printf("Not an even number greater than 2!!\n\n");
	else{
		for(i=2;i<=x/2;i++){
			if(check_prime(i)&&check_prime(x-i)){
				printf("%d+%d=%d\n",i,x-i,x);
				cnt++;
			}
		}
		printf("Number of Goldbach's partitions: %d\n\n",cnt);
	}
	return 0;
}
