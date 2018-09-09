//
// Created by Leo Tan on 27/10/17.
//

#ifndef SM2_C_PROGRAMMING_LAB8_2_H
#define SM2_C_PROGRAMMING_LAB8_2_H

#endif //SM2_C_PROGRAMMING_LAB8_2_H

# include <stdio.h>
# include <stdlib.h>

# define n 8

void swap(int* a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int q2()
{
    int G[n][n];
    int i,j;
    int interchange=0;
    int i1, j1;
    int row, col;
    long checksum, sorted;
    int k;


    srand (17);
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            G[i][j] = rand()%200;

    printf ("\n\nRaw Data:\n");
    checksum=0;
    for (i1=0; i1<n; i1++)
    {
        for ( j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);

    // pre-processing row sort to be programmed by you

    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--) {
            for(k=0;k<j;k++){
                if(G[k][i]>G[k+1][i]) swap(&G[k][i],&G[k+1][i]);
            }
        }
    }


    printf ("\n\nAfter row sort:\n");
    checksum=0;
    for (i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }

    printf ("Checksum = %ld",checksum);

    // pre-processing column sort to be programmed by you

    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--) {
            for(k=0;k<j;k++){
                if(G[i][k]>G[i][k+1]) swap(&G[i][k],&G[i][k+1]);
            }
        }
    }


    printf ("\n\nAfter column sort:\n");
    checksum=0;
    for ( i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);

    // exchange and heap restoration to be programmed by you

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i+1 < n && G[i][j]>G[i+1][0]){
                swap(&G[i][j],&G[i+1][0]);
            }
            row = i+1; col = 0;
            do{
                if(row+1 < n && G[row][col]>G[row+1][col]){
                    interchange = 1;
                    if(col+1 < n && G[row][col+1]<G[row+1][col]){
                        swap(&G[row][col],&G[row][col+1]);
                        col += 1;
                    } else {
                        swap(&G[row][col],&G[row+1][col]);
                        row += 1;
                    }
                } else if(col+1 < n && G[row][col]>G[row][col+1]){
                    swap(&G[row][col],&G[row][col+1]);
                    col += 1; interchange = 1;
                } else interchange = 0;
            }while(interchange);
            //interchange = 0;
        }
    }




    printf ("\n\nAfter interchange and restoration:\n");
    checksum=0;
    sorted =1;
    for (i1=0; i1<n; i1++)
    {
        for (j1=0; j1<n; j1++)
        {
            printf ("%5d",G[i1][j1]);
            checksum += G[i1][j1];
            if (! ( i1==(n-1) && j1 == (n-1) ) )
                if ( *(&G[0][0] + i1*n +j1) > *(&G[0][0] + i1*n +j1 + 1) )
                    sorted =0;
        }
        printf ("\n");
    }
    printf ("Checksum = %ld",checksum);

    if (sorted ==1) printf ("   sorted\n\n");
    else printf ("    not sorted\n\n");

    return 0;
}