/*
Name - Rajendra singh
Roll no. 111601017
Question - prins Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct adjlistnode//structure of node
{
   int vertex;
   int weight;
   struct adjlistnode *next;
}adjlistnode;

adjlistnode *newadjlistnode(int , int );

typedef struct heapnode//structure of node
{
   int vertex;
   int cost;
}heapnode;
heapnode *newheapnode(int , int);

typedef struct heap
{
    int currentsize;      //current size of heap
    int maxsize;  // maximum size of heap of min heap
    int *pos;     // ptr to the array of position(int) of heapnode in the array
    struct heapnode **array;  //ptr to the array of address(ptr to node) of heapnode in the array
}heap;

adjlistnode *head[200];

int V; //no. of vertices
int E; //no. of edges
int start = 0;
int cost[200];
int parent[200];
int minCostVertex;
int minCost;



void readfile();
void insertadjver(int ,int , int );
heap *Buildheap(int );
void prins(int);
void decreaseKey(heap* , int , int);
void swap(heapnode **, heapnode **);
heapnode *extractMin(heap *);
void minHeapify(heap *, int );




int main()/////////////////////////////////////////////////////////////////////////////////////////
{
	int i;
    readfile();

    prins(start);

	  printf("\nMINIMUM SPINING TREE EDGES ARE :\n");
    for (i = 1; i < V; i++)//dont want to include (0,0) that why staring with 1 and not with 0
    {
        if(i<parent[i])
        printf("(%d,%d)\n",i, parent[i]);
        else
        printf("(%d,%d)\n",parent[i], i);
    }
    return 0;
}




void readfile()///////////////////////////////////////////////////////////////////////////////////
{
  char filename[20];
  printf("\nEnter the filename : ");
  scanf("%s", filename);
	FILE *fptr;
    int u, v, weight;
	int success,r,w;
	int i = 0;
	fptr = fopen(filename, "r");

	if(fptr == NULL)//checking if file opened properly
	{
		printf("********File didn't open properly**********\n");
		return;
	}
	else
	{
		success = fscanf(fptr, "%d", &V);//reading no. vertex
		printf("\n%d\n",V);
    success = fscanf(fptr, "%d", &E);//reading no. edge
		printf("%d\n",E);

		for (i = 0; i < V; i++)
		{
    		head[i] = NULL;
 	 	}

		for(i=1; i<=E; i++)
		{
      		fscanf(fptr, "%d", &u);
      		fscanf(fptr, "%d", &v);
      		fscanf(fptr, "%d", &weight);
      		printf("%d %d %d\n",u,v,weight);
      		insertadjver(u,v,weight);
          insertadjver(v,u,weight);//since undirected graph
		}
	}
  fclose(fptr);
}



void insertadjver(int src,int des, int weight)  //src is source vertex and des is destination vertex/////////////////////////////////////////////////
{
    adjlistnode *p,*q;

    q=newadjlistnode(des, weight);

    if(head[src]==NULL)//insert the node head is NULL
        head[src]=q;
    else
    {
        p=head[src];

        while(p->next!=NULL)//go to end of the linked list
            p=p->next;
        p->next=q;
    }
}



//function to create new adjlistnode
adjlistnode *newadjlistnode(int vertex, int weight)///////////////////////////////////////////////////////////////////////////////////
{
	adjlistnode *p;
	p = (adjlistnode *)malloc(sizeof(adjlistnode));
	p->vertex = vertex;
	p->weight = weight;
	p->next = NULL;
	return(p);
}


//function to create new heapnode
heapnode *newheapnode(int vertex, int cost)///////////////////////////////////////////////////////////////////////////////////
{
	heapnode *p;
	p = (heapnode *)malloc(sizeof(heapnode));
	p->vertex = vertex;
	p->cost = cost;
	return(p);
}


//buildheap function
heap *Buildheap(int maxsize)///////////////////////////////////////////////////////////////////////////////////
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->currentsize = 0;//initilising currentsize 0 i.e biulding empty string
    h->maxsize = maxsize;
    h->pos = (int *)malloc(maxsize*sizeof(int));
    h->array = (heapnode **)malloc(maxsize*sizeof(heapnode *));
	return(h);
}



void prins(int start)///////////////////////////////////////////////////////////////////////////////////
{
	int i;
	heap *h = Buildheap(V);
	for(i = 0; i<V; i++)
	{
    parent[i] = INT_MAX;//initialising all parent with INT_MAX
		cost[i] = INT_MAX;//initialising all cost with INT_MAX
		h->array[i]= newheapnode(i,cost[i]);
		h->currentsize++;
		h->pos[i] = i;
	}
	cost[start] = 0;
  h->array[start]->cost = cost[start];
  parent[start] = start;
	decreaseKey(h, start, cost[start]);

	while(h->currentsize!=0)
    {
        heapnode* tempheapnode = extractMin(h);
        int u = tempheapnode->vertex;
        adjlistnode *p = head[u];
        while (p != NULL)//for all adjacent vertex of u i.e Extracted vertex
        {
            int v = p->vertex;
            if (p->weight < cost[v] && cost[u] != INT_MAX)
            {
                cost[v] = p->weight;//updating cost value
                decreaseKey(h, v, cost[v]);//recursive calling decreaseKey this adjacent vertex
                parent[v] = u;
            }
            p= p->next;
        }
    }
}



void decreaseKey(heap* h, int v, int cost)//decrease the value of node and hence shifting it////////////////////////////////////////////////////////
{
    int i = h->pos[v];
    h->array[i]->cost = cost;
    while ( (i!= 0) && h->array[i]->cost < h->array[(i - 1) / 2]->cost)//shift up the node v up in heap and updating its position(in heap position array) and address(in heap address array)
    {
        h->pos[h->array[i]->vertex] = (i-1)/2;//updating its position
        h->pos[h->array[(i-1)/2]->vertex] = i;
        swap(&h->array[i],  &h->array[(i - 1) / 2]);//updating its address
        i = (i - 1) / 2;
    }
}




void swap( heapnode**p, heapnode**q)// swap function for swaping ptr to heapnode//////////////////////////////////////////////////////////
{
    heapnode *temp = *p;
    *p = *q;
    *q = temp;
}


//funtion for deleting the minimum element from heap
heapnode *extractMin(heap *h)///////////////////////////////////////////////////////////////////////////////////
{
	int i;
    heapnode *minHeapnode, *lastHeapnode;
    minHeapnode = h->array[0]; //topmost node is the minimum
	lastHeapnode = h->array[h->currentsize-1];//last node i.e currentsize-1(since heap starting with 0)
	h->array[0] = lastHeapnode;//replacing first node address in address array with that of last node
	h->array[h->currentsize-1] = minHeapnode;

	h->pos[lastHeapnode->vertex] = 0;//first place
	h->pos[minHeapnode->vertex] = h->currentsize-1;//last place(where there will be no element in heap)

	h->currentsize--;//reducing the currentsize

	minHeapify(h,0);//calling the minHeapify at starting node


    return(minHeapnode);
}



void minHeapify(heap *h, int now)//heapify all element contected below now///////////////////////////////////////////////////////////////////////////////////
{
  int child;//child node position

  while((now*2+2) <= (h->currentsize))//while right child index is less or equal to heapsize
  {
	child = now*2 + 1;
	if (child != h->currentsize-1 && (h->array[child+1])->cost < (h->array[child])->cost) //gives the minimum child of now
  	{
  	  child++;
  	}

  	if((h->array[now])->cost > (h->array[child])->cost)//if heap[now] is greater(i.e unfit) than minimum child
  	{
		h->pos[h->array[now]->vertex] = child;
		h->pos[h->array[child]->vertex] = now;

		swap(&h->array[now], &h->array[child] );
	}
	else
	{
		return;
	}
	now = child;
  }
}

/*
SAMPLE INPUT:
9
15
0 1 4
0 7 8
1 2 7
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
4 7 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
