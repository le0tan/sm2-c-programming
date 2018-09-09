
/* ex2.c    Lab 2

this program is to be debugged */

/* Compute amount in bank account */

#include <stdio.h>


#define APR_TO_MDR   1200.0 

// For converting annual percentage rate to monthly decimal rate */

int main(void)
{
   float balance;		/* Current balance */
   float deposit;		/* Monthly deposit */
   float annual_pcnt_rate;	/* Annual percentage rate */
   float rate;			/* Monthly decimal rate */
   float interest;		/* Interest for this month */
   int months;			/* Number of months */
   int m;			/* Current month */

/* Get input data from user */

   printf("Starting balance: ");
   scanf("%f", &balance);
   printf("Monthly deposit: ");
   scanf("%f", &deposit);
   printf("Annual percentage rate: ");
   scanf("%f", &annual_pcnt_rate);
   printf("Number of months: ");
   scanf("%d", &months);

/* Computer new balance */

   rate = annual_pcnt_rate / APR_TO_MDR;

   for(m = 1; m <= months; m--)
   {
      balance += deposit;
      interest = balance * rate;
      balance += interest;
   }

   printf("Balance after %d months: $%.2f\n", months, deposit);
   return 0;
}


