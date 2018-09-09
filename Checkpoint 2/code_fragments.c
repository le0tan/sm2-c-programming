//5.1

#include <stdio.h>

int exp(){
	int c = 100;
	const int* a = &c;
	int* b;

	//*a = 10;
	//Prohibited because of the const prefix

	b = a;
	*b = 10;
	printf("%d\n",*a);
	return 0;
}

//5.2

#include <stdio.h>
#include <string.h>

int exp(){
	int a[100];
	memset(a,-1,sizeof(a));
	a[1] = 100;
	*(a+1) = 10;
	if(a == &a[0]) printf("Yes.\n");
	else printf("This will not be printed anyways.");
	printf("The size of array a is %u.\n",sizeof(a));
	return 0;
}

//5.3

#include <stdio.h>
#include <string.h>

int sum_2d(int *a, int count){
	//might as well written as int sum_2d(int a[], int count)
	//Writing a[100] doesn't affect the result because in function reference
	//the information of the size is ignored (i.e. a[100] is the same as a[])
	int i, sum = 0;
	for(i = 0;i < count;i++)
		sum += a[i];
	return sum;
}

int sum_3d(int *a, int count){
	//This is a useful trick to scan through n-dim array
	//Might as well written as int sum_3d(int a[][2], int dim1, int dim2)
	//Then use a[dim1][dim2] to scan through the array
	int sum = 0, i;
	for(i=0;i<count;i++){
		sum += *a;
		a++;
	}
	return sum;
}

int exp(){
	int a[] = {1,2,3,4,5};
	int b[2][2] = {1,2,
					3,4};
	printf("%d\n",sum_2d(a,sizeof(a)/sizeof(int)));
	printf("%d\n",sum_3d(b,sizeof(b)/sizeof(int)));
	//Funny things happen here because we passed illegal parameter (i.e. b)
	//to function sum_3d.
	//I explained this.
	return 0;
}

//5.4

#include <stdio.h>
#include <string.h>

int exp(){
	char a[100];
	char b[] = {'a','b','c'};
	char c[] = "abc";
	scanf("%10s",a);
	printf("%s\n",a);
	printf("%d %d\n",sizeof(b),sizeof(c));
	return 0;
}


//5.5

#include <stdio.h>
#include <string.h>

int exp(){
	int a,b;
	scanf("%d%*s%d",&b,&a);
	printf("%d\n",a);
	return 0;
}

//0.1
#include <stdio.h>
#define f(x) ((x)*(x)+2*(x)-3)
#define fpr(x) (2*(x)+2)
#define torlerance 0.00001

double New(double init){
	double now = init;
	while(fabs(f(now))>torlerance){
		now = now - f(now)/fpr(now);
	}
	return now;
}

double Ral(double now){
	if(fabs(f(now))<=torlerance) return now;
	else return Ral(now - f(now)/fpr(now));
}

//0.2

void Bub(int *arr, int length){
    int i,j,index,now,temp;
    for(i=0;i<length;i++){
        now = arr[i];
        index = i;
        for(j=i+1;j<length;j++){
            if(arr[j]<now) {
                index = j;
                now = arr[j];
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    return;
}

void Ble(int *arr, int length){
    int j,index,now,temp;
    if(length<=0) return;
    else{
        now = arr[0];
        index = 0;
        for(j=1;j<length;j++){
            if(arr[j]<now) {
                index = j;
                now = arr[j];
            }
        }
        temp = arr[0];
        arr[0] = arr[index];
        arr[index] = temp;
    }
    Ble(arr+1,length-1);
    return;
}

//0.3

void Bubble1(int *arr, int length){
    int i,j,temp,exchanged = 0;
    for(i=length-1;i>=1;i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                exchanged = 1;
            }
        }
        if(!exchanged) break;
        else exchanged = 0;
    }
    return;
}

void Bubble2(int *arr, int length){
    static int exchanged = 0;
    int i,temp;
    if(length<=1) return;
    for(i=0;i<length-1;i++){
        if(arr[i]>arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            exchanged = 1;
        }
    }
    if(exchanged) {
        exchanged = 0;
        Bubble2(arr,length-1);
    }
    else return;
    return;
}

//0.4