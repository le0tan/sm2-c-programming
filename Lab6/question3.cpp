#include <stdio.h>
#include <stdlib.h>

#define MAXN 256
#define SEED 47
#define INF 0x7f

void swap(int * a, int * b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}

int main(){
	int arr[MAXN];
	int i,j,k,l,cksm=0,cksm2=0,last=-INF,flag=0;
	
	srand(SEED);
	for(i=0;i<MAXN;i++) {
		arr[i] = rand();
		cksm+=arr[i];
	}

	
	for(i=MAXN-2;i>=0;i--){
		for(j=MAXN-1;j>i;j--){
			if(arr[j]<arr[i]){
				for(k=j;k>i;k--) swap(&arr[i],&arr[k]);
				break;
			}
		}
	}
	
	for(i=0;i<MAXN;i++) {
		//printf("%d ",arr[i]);
		cksm2+=arr[i];
		if(arr[i]<last){
			flag = 1;
		}
		last = arr[i];
	}

	if(!flag && (cksm==cksm2)) printf("Sorted!\n");
	else printf("Failed!\n");
	
	return 0;
}
