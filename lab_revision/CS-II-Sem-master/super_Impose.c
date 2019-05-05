#include<stdio.h>
int main()
{

	FILE *p1, *p2, *p3;
	int r,w,i, j, a[500][500], b[5],d[500][500],c[5];
	char magicno1[5],magicno2[5],inputfile1[20], outputfile[20], inputfile2[20];

	printf("Enter the two inputfile names\n");
	scanf("%s%s", inputfile1,inputfile2);
	printf("Enter the outputfile name\n");
	scanf("%s", outputfile);
	
	p1=fopen(inputfile1, "r");
	
	if(p1 == 0)
	{
		printf("File dint open correctly\n");
		return 1;
	}
	
	fscanf(p1, "%s", magicno1);
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


	p2=fopen(inputfile2, "r");
	
	if(p2 == 0)
	{
		printf("File dint open correctly\n");
		return 1;
	}
	
	fscanf(p2, "%s", magicno2);
	fscanf(p2, "%d%d", &c[0], &c[1]);
	fscanf(p2, "%d", &c[2]);
	
	for(i=0; i<b[0]; i++)
	{
		for(j=0; j<b[1]; j++)
		{ 
			fscanf(p2,"%d", &d[i][j]);
		}
	}
	
	fclose(p2);


	
	p3 = fopen(outputfile, "w");
	if(p3 == 0)
	{
		fprintf(p3,"File dint open correctly\n");
	}
	fprintf(p3,"%s\n%d %d\n%d\n", magicno1, b[0], b[1], b[2]);
	for(i=0; i<b[0]; i++)
	{
		for(j=0; j<b[1]; j++)
		{ 
			fprintf(p3,"%d ", (a[i][j]+d[i][j])/2);
		}
		fprintf(p3,"\n");
	}
	fclose(p3);


	return 0;
}
