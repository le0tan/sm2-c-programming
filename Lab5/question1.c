#include <stdio.h>

int main(void){
	
	FILE *in;
	if((in = fopen("bill.inf","r"))== NULL){
		printf("Unable to open the file.\n\n");
		return 0;
	};
	
	printf("Bill number \tPayment($)\n");
	printf("==========================\n");
	
	
	int a,b,c,d;
	double sum,total=0.0;
	
	while(fscanf(in,"%d%d%d%d",&a,&b,&c,&d)==4){
		sum = 0.0;
		if(b>100) sum += 4*(1-0.02)*b;
		else sum += 4*b;
		if(c>200) sum += 6*(1-0.05)*c;
		else sum += 6*c;
		if(d>150) sum += 5*(1-0.1)*d;
		else sum += 5*d;
		total += sum;
		printf("%d\t\t%.2lf\n",a,sum);
		printf("--------------------------\n");
	} 
	printf("Total payment: $%.2lf\n\n",total);
	fclose(in);
	
	return 0;
}
