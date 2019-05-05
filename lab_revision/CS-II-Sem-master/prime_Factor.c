#include<stdio.h>
int main()
{
	int n,i,j,k,t=0;
	printf("Enter an integer(n>2):");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		if (n%i==0)
		{
			for (k=1; k<=i; k++)
			{
				if (i%k==0)
				{
					t=t+1;
				}
			}
			if (t==2)
			{
				printf("%d, ", i);
			}
			t=0;
		}
        }
	printf("\n");
	return 0;
}
