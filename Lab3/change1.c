
/* this program is to be debugged */

/* File change.c */
/* Program to make change */

# include <stdio.h>

/* Define values of coins */

#define HALF	50
#define QUARTER	25
#define DIME	10
#define NICKEL	 5

int main(void)
{
  int change;      /* Amount of change yet to be returned */
  int coins;       /* Number of coins to be returned for
		      a particular denomination */

  printf("Enter amount of change in cents: ");
  scanf("%d", &change);

  coins = change / HALF;
  change = change % HALF;
  printf("%-9s  %2d\n", "Halves:", coins);

  coins = change % QUARTER;
  change = change / QUARTER;
  printf("%-9s  %2d\n", "Quarters:", coins);

  coins = change / DIME;
  change = change % DIME;
  printf("%-9s  %2d\n", "Dimes:", coins);

  coins = change / NICKEL;
  change = change % NICKEL;
  printf("%-9s  %2d\n", "Nickels:", coins);

  printf("%-9s  %2d\n", "Pennies:", change);

  return 0;
}

