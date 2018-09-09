// ex1.c 

// to be debugged. Lab2

# include <stdio.h> 

main() 
{   
 
  int i, sum = 0;
  
  for (i=1; i<=99; i++)
	sum = sum+i;

  printf ("1 + 2 + 3 + 4 + ... + 97 + 98 + 99 = %d\n\n", sum);

  return 0;
}
