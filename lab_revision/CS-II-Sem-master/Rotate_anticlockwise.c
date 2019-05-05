/* This the program do anticlockwise rotation of a image and puting all images(after each anticlockwise rotation, starting from image itself) in a single image in anticlockwise fasion of quadrants starting from left bottomost quadrant 

NAME - RAJENDRA SINGH */


#include<stdio.h>
int main()
{




	FILE *p, *q; /* declaration of pointers to the file */
	int success,r,i=0,j=0, d[5], w;
	int a[500][500];			/* declaration of orignal image matrix*/
	int b[1000][1000];			/* declaration of final image matrix*/
	char inputfile[30], outputfile[30], magicno[5];

	printf("Enter the name of file to open\n");  //*asking for the input file name
	scanf(" %s", inputfile);
	printf("Enter the name of output file\n");   //*asking for the output file name
	scanf(" %s", outputfile);


	p=fopen(inputfile,"r");      //* opening the file in only readable type

	if(p==0)
	{
		printf("Error occur in opening file\n");
		return 1;
	}

	fscanf(p, "%s", magicno);		//* This is for scaning the magic no.,width and hight, maximum intensity value 
	fscanf(p, "%d %d", &d[0], &d[1]);
	fscanf(p, "%d", &d[2]);
	for(i=0; i<d[1]; i++)             //* for scaning the image matrix
	{
		for(j=0; j<d[0]; j++)
		{
			fscanf(p,"%d", &a[i][j]);			
		}
	}
	fclose(p);	//*closeing the above file since scaning over












//*Below is the program for defining the final image matrix from our scaned orignal image

	
	for(i=0; i<d[1]; i++)      /* for defining the left upper quadrant of final image from orignal image*/                       
	{
		for(j=0; j<d[0]; j++)
		{
			b[i][j]= a[d[1]-i][i];
		}
	
	}

	
	for(i=0; i<d[0]; i++)    /* for defining the right upper quadrant of final image from orignal image*/ 
	{
		for(j=d[0]; j<(d[0]+ d[1]); j++)
		{
			b[i][j]= a[d[0]-i][(d[0] + d[1])-j];
		}
	
	}

	for(i=d[1]; i<(d[1] + d[0]); i++)    /* for defining the left bottom quadrant of final image from orignal image*/ 
	{
		for(j=0; j<d[0]; j++)
		{
			b[i][j]= a[i-d[1]][j];
		}
	
	}
 

	for(i=d[1]; i<(d[1] + d[0]); i++)	/* for defining the right bottom quadrant of final image from orignal image*/ 
	{
		for(j=d[0]; j<(d[0]+ d[1]); j++)
		{
			b[i][j]= a[j-d[0]][(d[0]+d[1])-1];
		}
	
	}








 



	q=fopen(outputfile, "w");   //*opening the new file in only writable type
	if (q==0)
	{
		fprintf(q,"File dint open correctly\n");
	}
	fprintf(q,"%s\n%d %d\n%d\n", magicno, d[0], d[1], d[2]);
	for(i=0; i<(d[1]+d[0]); i++)  //*printing the final image matrix
	{
		for(j=0; j<(d[0]+d[1]); j++)
		{
			fprintf(q,"%d ", b[i][j]);
		}
		fprintf(q,"\n");
	}
	fclose(q);	//*closeing the above file
	
		
	return 0;
} 
			
