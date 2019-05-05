#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char smallstr[100], bigstr[200];
	char *p;
	int position, i=0;

	printf("Enter bigger string\n");
	scanf(" %[^\n]s", bigstr);

	printf("Enter smaller string\n");
	scanf(" %[^\n]s", smallstr);
	
	printf("Big string after transformation to lowercase is:-\n");
	while(bigstr[i])
	{
		putchar(tolower(bigstr[i]) );
		i++;
	}
	printf("\nsmall string after transformation to lowercase is:-\n");
	i=0;
	while(smallstr[i])
	{
		putchar(tolower(smallstr[i]) );
		i++;
	}

	
	printf("\n");
	p = strstr(bigstr,smallstr);

	if (p==0)
	printf(" '%s' is not contained in '%s' \n", smallstr,bigstr);
	else
	{
		position = (int)(p-bigstr);
		printf(" '%s' is contained in '%s' starting from the position %d \n", smallstr,bigstr, position);
	}

	
	return 0;
}
