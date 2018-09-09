//currency.c

#include <stdio.h>

void print_menu(void)
{
	printf("\n\n   Currency Conversion\n");
	printf("1.   Customer sells Renminbi\n");
	printf("2.   Customer buys Renminbi\n");
	printf("3.   Quit\n\n");
	printf("Enter your choice: ");
}

int main(void)
{
	//Declaration
	FILE *in;
	int buy,sell,arg;
	//File I/O
	if((in = fopen("RATE.DAT","r"))== NULL){
		printf("Unable to open the file.\n\n");
		return 0;
	}
	fscanf(in,"%d%d",&buy,&sell);
	fclose(in);
	//Init
	print_menu();
	//Main programme
	while(scanf("%d",&arg)){
		//char temp = getchar();
		if(arg == 3){
			printf("Have a nice day!\n\n");
			break;
		}
		if(arg == 1){
			double rmb;
			printf("How much RMB are you selling? ");
			scanf("%lf",&rmb); getchar();
			printf("\nFor %.2lf CNY (Chinese Yuan Renminbi) you will get %.2lf SGD (Singapore Dollar).",rmb,rmb*buy/1000.0);
		}
		else if(arg == 2){
			double sgd;
			printf("How much SGD are you selling? ");
			scanf("%lf",&sgd);
			getchar();
			printf("\nFor %.2lf SGD (Singapore Dollar) you will get %.2lf RMB (Chinese Yuan Renminbi).",sgd,sgd*sell/100.0);
		} else {
			printf("Invalid command--please try again.");
		}
		print_menu();
	}
	return 0;
}
