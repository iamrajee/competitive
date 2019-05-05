#include<stdio.h>
int main()
{

	FILE *p1, *p2;
	int r,w,i, j, a[500][500], b[5];
	char magicno[5],inputfile[20], outputfile[20];
	
	printf("Enter the inputfile name\n");
	scanf("%s", inputfile);
	printf("Enter the outputfile name\n");
	scanf("%s", outputfile);
	
	p1=fopen(inputfile, "r");
	
	if(p1 == 0)
	{
		printf("File dint open correctly\n");
		return 1;
	}
	
	fscanf(p1, "%s", magicno);
	fscanf(p1, "%d%d", &b[0], &b[1]);
	fscanf(p1, "%d", &b[2]);
	
	for(i=0; i<b[0]; i++)
	{
		for(j=0; j<b[1]; j++)
		{ 
			fscanf(p1,"%d", &a[i][j]);
		}
	}
	
	fclose(p1);

	
	p2 = fopen(outputfile, "w");
	if(p2 == 0)
	{
		fprintf(p2,"File dint open correctly\n");
	}
	fprintf(p2,"%s\n%d %d\n%d\n", magicno, b[0], b[1], b[2]);
	for(i=0; i<b[0]; i++)
	{
		for(j=b[1]-1; j>=0; j--)
		{ 
			fprintf(p2,"%d ", a[i][j]);
		}
		fprintf(p2,"\n");
	}
	fclose(p2);


	return 0;
}

