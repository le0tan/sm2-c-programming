//pack.c  
// pack string with only alphabets

#include <stdio.h>
#include <string.h>

void process (char*);

int main()
{
    char string[100];

    printf("Enter a string of not more than 99 characters: ");
    gets(string);
	printf ("The length of string before packing is %d\n", strlen (&string[0]) );
	process (string);
    printf("Packed String: %s\n",string);
	printf ("The length of string after packing is %d\n", strlen (&string[0]) );

    return 0;
}

void process (char s[])
{
	// to be filled in by you.


}