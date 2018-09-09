#include <stdio.h>

int main(){
	FILE *in, *out;
	char buff[256];
	float hours,rate,wage;
	int num;
	in = fopen("wage.inf","r");
	out = fopen("wage.ouf","w");
	
	printf("Employee No.   Hours Worked   Hourly Rate      Wage\n");
	printf("                   (hr)          ($/hr)         ($)\n");
	printf("===================================================\n");
	while(fgets(buff,14,in)!=NULL){
		fscanf(in,"%d%*c%*c",&num);
		fscanf(in,"%f",&rate);
		//printf("%d %.2f ",temp,ft);
		fscanf(in,"%f%*c",&hours);
		//printf("%.2f\n",ft);
		printf("    %d           %.2f\t %.2f\t     %.2f\n",num,hours,rate,rate*hours);
	}

	fclose(in);	fclose(out);
	return 0;
}
