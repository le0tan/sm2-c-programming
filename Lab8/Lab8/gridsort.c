// Square Grid Sort
// This is a structured sorting algorithm

# include <stdio.h>
# include <stdlib.h>

# define n 8

main ()
{
      int G [n][n];

      int i,j,this1;
      int nexti, nextj, temp, interchange;
      int thisi, thisj,  min;

      int i1, j1;
      int row, col;
      long checksum, sorted;

	  // add new indentifiers if you need




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

