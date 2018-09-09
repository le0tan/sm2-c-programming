/****             2048 Game in C Programming Language              ****/
/**** squeeze functions and random blocks functions to be continued****/



#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int left_sqz(int* row[], int cnt){
	int new_cnt = cnt;
	
	return new_cnt;
}

void move(char dir, int brd[][4]){
	switch(dir){
		case 'l':{
			for(int i=0;i<4;i++){
				bool flag = false;
				while(!flag){
					int cnt=0;
					int row[6];
					memset(row,-1,sizeof(row));
					for(int j=0;j<4;j++){
						if(brd[i][j]!=-1){
							row[cnt]=brd[i][j];
							cnt++;
						}
					}
					if(cnt==0) flag = true;
					else{
						bool flag2 = true;
						while(flag2){
							int new_cnt = left_sqz(row,cnt);
							if(new_cnt == cnt) flag2 = false;
							else cnt = new_cnt;
						}
					} 
				}
			}	
			break;
		}
		case 'r':{
			printf("r\n");
			break;
		}
		case 'u':{
			printf("u\n");
			break;
		}
		case 'd':{
			printf("d\n");
			break;
		}
		default : printf("Invalid input, please try again!\n");
	}
	return;
}

void randomly_add(int brd[][4]){
	
	return;
}

//{{2,2,4,4},
//{2,2,4,4},
//{2,2,4,4},
//{2,2,4,4},
//}


int main(){
	int board[4][4];
	memset(board,-1,sizeof(board));
	board = {{2,2,4,4},
{2,2,4,4},
{2,2,4,4},
{2,2,4,4},
};
	bool flag = true;
	while(flag){
		randomly_add();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(board[i][j]==-1) printf("  *   ");
				else printf("%5d ",board[i][j]);
			}
			printf("\n");
		}
		printf("What's your next move? (l/r/u/d): ");
		char dir;
		scanf("%c",&dir);
		if(dir == '\n') scanf("%c",&dir);
		move(dir,board);
		
	}
	return 0;
}
