#include <stdio.h>
#define MAX_LEN 256

int price(char label){
	int p[]={9,9,9,15,15,15,15,5,5,5,5,12,12,12,12};
	return p[label - 'A'];
}


int main(void){
	//Read and create the files.
	FILE *in,*out;
	if((in = fopen("medicine.inf","r")) == NULL){
		printf("Unable to open file.\n\n");
			return 0;
	}
	if((out = fopen("charges.ouf","w")) == NULL){
		printf("Unable to create file.\n\n");
		return 0;
	}
	
	fprintf(out,"  Bill No.\t\tPrescription Charge($)\n");
	fprintf(out,"==================================\n");
	
	//Main programme
	int bill,num;
	while(fscanf(in,"%d%d",&bill,&num) == 2){
		//printf("Bill:%d Num:%d\n",bill,num);
		int i;
		double sum=0.0;
		char t;
		int q;
		fscanf(in,"%c",&t);
		for(i=0;i<num;i++){
			fscanf(in,"%c",&t);
			fscanf(in,"%d",&q);
			sum += price(t) * q;
		}
		fscanf(in,"%c",&t);
		fprintf(out,"    %d\t\t\t   %.2lf\n",bill,sum);
	}
	//Clean-up
	fclose(in); fclose(out);
	return 0;
}
