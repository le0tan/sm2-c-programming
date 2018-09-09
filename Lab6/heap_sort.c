#include <stdio.h>

void swap(int* a,int* b){
    int temp = *b; *b = *a; *a = temp; return;
}

void sift_up(int* A, int idx, int len){
    int largest_son;
    if(idx*2+1>len) return;
    if(idx*2+2>len) largest_son = idx*2+1;
    else if(A[idx*2+1]>A[idx*2+2]) largest_son = idx*2+1;
    else largest_son = idx*2+2;
    if(A[largest_son]>A[idx]){
        swap(&A[idx],&A[largest_son]);
        sift_up(A,largest_son,len);
    } else return;
}

void build_heap(int *A, int len){
    int i;
    for(i=len;i>=0;i--) sift_up(A,i,len);
    return;
}

void heap_sort(int *A, int len){
    int i,last = len;
    build_heap(A, len);
    for(i=0;i<len;i++){
        swap(&A[0],&A[last--]);
        sift_up(A, 0, last);
    }
    return;
}

int main(){
    int a[]={1,5,2,3,6,1,4,4,7,8,9,1,2};
    int i,len = sizeof(a)/sizeof(int)-1;
    
    printf("The original array: ");
    for(i=0;i<=len;i++) printf("%d ",a[i]);
    printf("\n");
    
    heap_sort(a,len);
    
    printf("After heap sorting: ");
    for(i=0;i<=len;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}