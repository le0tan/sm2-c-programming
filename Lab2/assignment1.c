#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>÷
#define REP(a,b) for(i=a;i<b;i++)
#define DURATION 1
#define LINE 21

void fold_pos(int space){
	int i,j;
	REP(0,4){
		for(j=0;j<space;j++) printf(" ");
		for(j=0;j<3-i;j++) printf(" ");
		printf("/");
		for(j=0;j<=i*2;j++) printf(" ");
		printf("\\");
		for(j=6-i*2;j>0;j--) printf(" ");
		printf("/");
		for(j=0;j<=i*2;j++) printf(" ");
		printf("\\");
		printf("\n");
	}
	return;
}

void stait_pos(int space){
	int i;
	REP(0,space) printf(" ");
	printf("           ^\n");
	REP(0,space) printf(" ");
	printf("          /\\\n");
	REP(0,space) printf(" ");
	printf("_________//_________\n");
	return;
}

void bird(int x,int y){
	int i;
	for(i=1;i<y;i++) printf("\n");
//	for(i=1;i<x;i++) printf(" ");
	fold_pos(x);
	sleep(DURATION);
	system("clear");
	for(i=0;i<y;i++) printf("\n");
	stait_pos(x);
	sleep(DURATION);
	system("clear");
	return;
}

int main(){
	int i;
	REP(0,LINE) bird(i+1,LINE-i);
	return 0;
}
