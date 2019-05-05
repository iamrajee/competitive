//* width n height
#include<stdio.h>
int main()
{


	FILE *p, *q;
	int success,r,i=0,j=0, a[500][500], d[5], w, h;
	char inputfile[30], outputfile[30], magicno[5];

	printf("Enter the name of file to open\n");
	scanf(" %s", inputfile);
	printf("Enter the name of output file\n");
	scanf(" %s", outputfile);


	p=fopen(inputfile,"r");

	if(p==0)
	{
		printf("Error occur in opening file\n");
		return 1;
	}

	fscanf(p, "%s", magicno);
	fscanf(p, "%d %d", &d[0], &d[1]);
	fscanf(p, "%d", &d[2]);
	for(i=0; i<d[0]; i++)
	{
		for(j=0; j<d[1]; j++)
		{
			fscanf(p,"%d", &a[i][j]);			
		}
	}
	fclose(p);


	for(i=0; i<d[0]; i++)
	{
		for(j=0; j<d[1]; j++)
		{
			a[i][j] = d[2]-a[i][j];
		}
	}



	q=fopen(outputfile, "w");
	if (q==0)
	{
		fprintf(q,"File dint open correctly\n");
	}
	fprintf(q,"%s\n%d %d\n%d\n", magicno, d[0], d[1], d[2]);
	for(i=0; i<d[0]; i++)
	{
		for(j=0; j<d[1]; j++)
		{
			fprintf(q,"%d ", a[i][j]);
		}
		fprintf(q,"\n");
	}
	fclose(q);	
	
		
	return 0;
} 
					
				





	
