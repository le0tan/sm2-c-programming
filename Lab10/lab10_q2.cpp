#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define seed 47

int con[8][7] = {};
int order[13] = {};
int best[13];
const int cx[13] = {};
const int cy[13] = {};

void swap(int* a, int* b){
	int temp = *a;
	*a = *b; *b = temp;
	return;
}

int exchange(int a,int b){//make sure a<b
	if(con[b][order[(a+13-1)%13]] && con[a][order[(b+1)%13]]){
		swap(&order[a], &order[b]);
		return 1;
	} else return 0;
}

double dist(){
	int i;
	double ans = 0.0;
	ans += sqrt((cx[0]-cx[12])*(cx[0]-cx[12])+(cy[0]-cy[12])*(cy[0]-cy[12]))
	for(i=1;i<13;i++){
		ans += sqrt((cx[i]-cx[i-1])*(cx[i]-cx[i-1])+(cy[i]-cy[i-1])*(cy[i]-cy[i-1]));
	}
	return ans;
}

int main(){
	double temp = 1000, rate = 0.1, lowest_temp = 100;
	double new_len, best_len, cur_len;
	double r, cost;
	int a;
	srand(seed);
	memcpy(best,order,sizeof(order));
	best_len = cur_len = dist();
	
	
	do{
		do{
			a = rand() % 13
		} while(a<12);
		
		if(exchange(a,a+1)){
			new_len = dist();
			if(new_len<cur_len){
				cur_len = new_len;
				if(cur_len < best_len){
					best_len = cur_len;
					memcpy(best,order,sizeof(order));
				}
			} else{
				r = (float)rand()/RAND_MAX;
				cost = (cur_len - best_len)/temp;
				if(r<exp(-cost)){
					cur_len = new_len;
				} else {
					exchange(a,a+1);
				}
			}
		}
		temp -= rate;
	}while(temp >= lowest_temp)
	
	return 0;
}
