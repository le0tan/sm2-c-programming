#include <stdio.h>

int multiply (int,int);

int main(){
	int a,b,negative=0,ans;
	printf("Enter two integers to be multiplied: ");
	scanf("%d%d",&a,&b);
	if(a==0||b==0)
		printf("%d*%d=0",a,b);
	else{
		if(a>0&&b<0){
			negative = 1;
			b = -b;
		} else if(a<0&&b>0){
			negative = 1;
			a = -a;
		}
		ans = multiply(a,b);
		if(!negative) printf("%d*%d=%d",a,b,ans);
		else printf("%d*%d=-%d",a,b,ans);
	}
	return 0;
}

int multiply(int a,int b){
	int iter=1,oa=a,tb=b;

	if(a==1) return b;
	if(b==1) return a;

	while(b-iter-iter>=0){
		a += a;
		iter += iter;
		b = tb-iter;
	}
	if(b>0) a+=multiply(oa,b);
	return a;
}
