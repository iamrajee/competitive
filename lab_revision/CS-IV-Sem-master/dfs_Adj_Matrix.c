/*
Name : Rajendra Singh
Roll no : 111601017
Question : DFS Algorithm
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *G[200];//heads of linked list
int visited[200];
int vertexno;//no. of vertex
void readfile(char* ); //reading adjacency list
void insertadjver(int,int);//insert an edge (src,des) in te adjacency list
void DFS(int);//dfs main function

void main()
{
    int i;
    char filename[20];
    printf("Enter the filename: " );
    scanf("%s",filename );
    readfile(filename);


    for(i=0;i<vertexno;i++) //initialised visited to 0
        visited[i]=0;

    printf("\nprinting the dfs sequence with 0 as starting vertex:\n"s );
    DFS(0);//calling the dfs vertex 0
    printf("\n" );
}

void DFS(int i)//dfs function defination
{
    node *p;

    printf("->%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)//print all adjacent vertex of i
    {
       i=p->vertex;

       if(!visited[i])
            DFS(i);//recursively next dfs
        p=p->next;
    }
}

void readfile(char* filename)
{
	FILE *fptr;
	int success,r,w;
	int i = 0,tempvertex = 0;
  printf("\nfilename = %s\n", filename );
	fptr = fopen(filename, "r");

	if(fptr == NULL)//checking if file opened properly
	{
		printf("********File didn't open properly**********\n");
		return;
	}
	else
	{
		success = fscanf(fptr, "%d", &vertexno);//reading vertex no.
		printf("\n%d\n",vertexno);

		for(i=0; i<vertexno; i++)
		{
      G[i] = NULL; //initialising heads to be zero
      tempvertex = 0;
			while(tempvertex != -1) //reading the adjacent vertex of vertex i
      {
				success = fscanf(fptr, "%d", &tempvertex);
        printf("%d\t", tempvertex);
        if(tempvertex == -1)//read until -1 is read
        {
          break;
        }
        else
        {
          insertadjver(i,tempvertex);//if read element is not -1 then insert into adjacency list
        }
      }
      printf("\n");
		}

	}
  fclose(fptr);
}

void insertadjver(int src,int des)  //src is source vertex and des is destination vertex
{
    node *p,*q;

    q=(node*)malloc(sizeof(node));//acquire memory for the new node
    q->vertex=des;
    q->next=NULL;

    if(G[src]==NULL)//insert the node in the linked list number vi
        G[src]=q;
    else
    {
        p=G[src];

        while(p->next!=NULL)//go to end of the linked list
            p=p->next;
        p->next=q;
    }
}
/*
SAMPLE GRAPH FILE 1:
7
1 6 -1
3 4 6 -1
5 -1
2 -1
5 -1
-1
2 -1

SAMPLE GRAPH FILE 1:
7
1 5 -1
0 2 3 -1
1 4 -1
1 4 5 -1
2 3 6 -1
0 3 6 -1
4 5 -1
*/
