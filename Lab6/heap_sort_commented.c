#include <stdio.h>


//Swapping two integers
void swap(int* a,int* b){
    int temp = *b; *b = *a; *a = temp; return;
}

//*A stands for the array to be sorted
//idx stands for the InDeX number of the node to be sifted up
//len stands for the length of the array to be sorted
//notice that len varies as the array to be sorted getting shorter
//because we DETERMINE the biggest number once at a time
void sift_up(int* A, int idx, int len){
    int largest_son;
    if(idx*2+1>len) return;		//If there is no son for node[idx], we do nothing
    if(idx*2+2>len) largest_son = idx*2+1;	//If there is only a left son, we let it be the largest son
    else if(A[idx*2+1]>A[idx*2+2]) largest_son = idx*2+1;	//If there are two sons, we compare them
    else largest_son = idx*2+2;
    if(A[largest_son]>A[idx]){	//If son is bigger than father
        swap(&A[idx],&A[largest_son]);
        sift_up(A,largest_son,len);		//We re-assign the sifting up target to be the father which now sits in the position of its previous son
    } else return;
}

//Just, build the heap by applying sifting up to every node
void build_heap(int *A, int len){
    int i;
    for(i=len;i>=0;i--) sift_up(A,i,len);
    return;
}

void heap_sort(int *A, int len){
    int i,last = len;
    build_heap(A, len);
    for(i=0;i<len;i++){//We do the sift_up operation for n times
    	//We decrease the variable last to make sure we do NOT touch the DETERMINED largest numbers in the end of the array
    	//Otherwise, the worst case time complexity would be O(n^2logn) instead of O(nlogn)
        swap(&A[0],&A[last--]);
        sift_up(A, 0, last);//This sift_up operation includes at most logn iterations since the "height" of every node is logn
        					//However, it is obvious that the height is decreasing, in reality it should be smaller.
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