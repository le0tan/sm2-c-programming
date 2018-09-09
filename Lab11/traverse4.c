
/* april 2012 q19 traversing a maze. 
   
   traverse4.c
   Travsere only four possibilities: down, right, up, left.
*/

#include <stdio.h>
#include <string.h>

#define N 6


void print (int this1[N][N])
{ 
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (this1[i][j]==0) printf (" ");
			else printf ("%c",219);
		}
			printf ("\n");
	}
}

// Your own recursive function for traversing in four directions

void fill(int vis[N][N],int m[N][N],int x,int y){
	if(!m[x][y] && !vis[x][y]){
		vis[x][y] = 1;
		if(x+1<N) fill(vis,m,x+1,y);
		if(y+1<N) fill(vis,m,x,y+1);
		if(x-1>=0) fill(vis,m,x-1,y);
		if(y-1>=0) fill(vis,m,x,y-1);
	}
	return;
}

int main()
{
	int vis[N][N];
	
	int maze1 [N][N]= {0, 0, 1, 0, 0, 1,           
	                   1, 0, 1, 0, 1, 1,
	                   1, 0, 0, 0, 1, 0,
	                   1, 0, 1, 1, 1, 1,
					   1, 0, 0, 0, 0, 0,
	                   1, 1, 1, 1, 1, 0};

	int maze2 [N][N]= {0, 0, 1, 0, 0, 0,           
	                   1, 0, 1, 0, 1, 0,
	                   1, 0, 0, 0, 1, 0,
	                   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 0,
	                   1, 1, 1, 1, 1, 0};
	
	int maze3 [N][N]= {0, 0, 1, 0, 0, 0,           
	                   1, 0, 1, 0, 1, 0,
	                   1, 0, 0, 0, 1, 0,
	                   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 1,
	                   1, 1, 1, 1, 1, 0};

	print (maze3);
    printf ("\n\nFour directional Traversal:\n");

	memset(vis,0,sizeof(vis));
	fill(vis,maze3,0,0);
	print(vis);
	if(vis[N-1][N-1]==0) printf("\nNo");
	else printf("\nYes");

	return 0;
}
