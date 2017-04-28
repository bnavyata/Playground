// C program to reverse a string using recursion
# include <stdio.h>

/* Function to print reverse of the passed string */
void reverse(char *str)
{
	if (str[0] == '\0') return;
	reverse(str + 1);	
	printf("%c", str[0]);	
}

/* Driver program to test above function */
int main()
{
	char *a = "Geeks for Geeks";	
	reverse(a);
	return 0;
}