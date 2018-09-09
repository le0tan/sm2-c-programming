
// gets.c  example

#include <stdio.h>
#include <string.h>

int main()
{
   char this1[11]; // 10+1

   printf("Enter a string of not more than 10 characters : ");
   gets(&this1[0]);

   printf("Your string is:%s", this1);

   printf ("\nIt contains %d characters.\n", strlen(&this1[0]));
   printf ("\nIt contains %d characters from [2].\n", strlen(&this1[2]));

   return 0;
}
