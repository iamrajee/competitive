/*
Name - Rajendra Singh
Roll No. - 111601017
Question : indicate if graph dag or not. if then print topological sorting otherwise print print any one cycle(one encountered first)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node//structure of node
{
   int vertex;
   struct node *next;
}node;

node *head[50];


typedef struct stack//structure of a stack
{
   int data;
   struct stack *next;
}stack;
stack *top=NULL;

int previs[50];
int posvis[50];
int active[50];
int count=0; //counter for count the on which no i am visiting a vertex and on which no, i'm leaving it
int flag=0;//initialising flag with 0 i.e non cycle if cycle comes flag = 1
int vertexno;//size of graph

void readfile();// function to read inputfile
void dfs(int u);
void printlist(int n);
void push(int );
int  pop();
void init();//function for initialising previs, posvis, active as 0
void insertadjver(int ,int ); //inserting a uv edge






int main()////////////////////////////////////////////////////main function
{
  int i;
  char filename[20];
  printf("Enter the filename: " );//asking filename
  scanf("%s",filename );
  readfile(filename);


   for(i=0; i<vertexno; i++)//calling dfs
   {
       if(previs[i]==0)
            dfs(i);
    }


   if(flag==1)//printing cycle
   {
       printf("\n\n****Input graph have a cycle and the cycle is:****\n");
       int temp1;
       for(i=0; temp1 != (-INT_MAX); i++)
        {
          printf("->" );
           temp1 = pop();
        }
    }
   else
   {
        printf("\n\ntopology sort is a DAG & sorting order is:\t");//printing topological order
        for(i=0; i<vertexno; i++)
        {
           pop();
           printf(",");
        }
    }



 return 0;
}////////////////////////////////////////////////////////////////////////////

void init()/////////////
{
  for (int i = 0; i < vertexno; i++)
  {
    previs[i]=0;  // array to store previsit of vertex
    posvis[i]=0;  //array to store postvisit of a vertex
    active[i]=0;  // array to store whether a vertex is in the current stack or not
  }
}

void readfile(char* filename)///////////readfile function
{
	FILE *fptr;
	int success,r,w;
	int i = 0,tempvertex = 0;
//  printf("\nfilename = %s\n", filename );
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
      head[i] = NULL; //initialising heads to be zero
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

    if(head[src]==NULL)//insert the node in the linked list number vi
        head[src]=q;
    else
    {
        p=head[src];

        while(p->next!=NULL)//go to end of the linked list
            p=p->next;
        p->next=q;
    }
}


void dfs(int u)///////////////////////////////////////////
{
  printf("\ndfs at %d:\t", u);
  if(flag==1)
      return ;

  count++;
  previs[u] = count;
  active[u] = 1;

  node *p   = head[u];

  while(p!=NULL)
  {
     if(previs[p->vertex]==0)
     {
        printf("tree edge is %d->%d\t",u,p->vertex);
        dfs(p->vertex);
     }
     else if(previs[p->vertex]>previs[u]) //p is previously visited after visiting u
     {
         printf("forward edge is %d->%d\t",u,p->vertex);
     }
     else if(active[p->vertex]==0) //previously visited adjacent vertex
     {
         printf("cross edge is %d->%d\t",u,p->vertex);
     }
     else//rest cases are back edge case so flag = 1 i.e cycle is present
     {
          flag=1;
          printf("back edge is %d->%d\t",u,p->vertex);
          push(p->vertex);
          active[u]=0;
          count++;
          posvis[u]=count;
          push(u);
          return;
     }
     p=p->next;
 }
    active[u]=0;
    count++;
    posvis[u]=count;
    push(u);
}


void push(int data)//////////////////
{
   if(top==NULL)
  {
    top=(stack *) malloc(sizeof(stack));
    top->data = data;
    top->next = NULL;
   }
   else
   {
      stack  *temp=(stack *) malloc(sizeof(stack));
      temp->data = data;
      temp->next=top;
		  top=temp;
   }
   return;
 }

int  pop()////////////////////
{
  int y;
  struct stack* temp;
  if(top==NULL)
    return(-INT_MAX);
  else
  {
	   temp=(struct stack*) malloc(sizeof(struct stack));
	   temp=top;
	   top=top->next;
     y=temp->data;
     printf("%d",y);
     free(temp);
  }
  return y;
}

/*
SAMPLE GRAPH FILE :with back edge
7
1 6 -1
2 -1
0 3 5 -1
4 5 -1
-1
-1
2 -1

SAMPLE GRAPH FILE 2 :without back edge
7
1 6 -1
2 -1
3 5 -1
4 5 -1
-1
-1
2 -1
*/
