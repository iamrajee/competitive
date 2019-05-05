/*
Name - Rajendra singh
Roll no. 111601017
Question - dijkstra
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
   int dist;
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
int start;
int dist[200];


void init();
void readfile();
void insertadjver(int ,int , int );
heap *Buildheap(int );
void dijkstra(int );
void decreaseKey(heap* , int , int);
void swap(heapnode **, heapnode **);
heapnode *extractMin(heap *);
void minHeapify(heap *, int );




int main()/////////////////////////////////////////////////////////////////////////////////////////
{
	int i;
    init();
    readfile();

    dijkstra(start);

	printf("Minimum distance of vertices from the start vertex are :\n");
    for (i = 0; i < V; i++)
        printf("Between start vertex (%d) and (%d) distance is (%d)\n",start, i, dist[i]);
    return 0;
}




void init()//////////////////////////////////////////////////////////////////////////////////////
{
	int i;
	for (i = 0; i < V; i++)
	{
    	head[i] = NULL;
		dist[i] = INT_MAX;
 	 }
}




void readfile()///////////////////////////////////////////////////////////////////////////////////
{
  char filename[20];
  printf("\nEnter the filename : ");
  scanf("%s", filename);
  //printf("\nflag1:%s\n",filename);
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

		for(i=1; i<=E; i++)
		{
      fscanf(fptr, "%d", &u);
      fscanf(fptr, "%d", &v);
      fscanf(fptr, "%d", &weight);
      printf("%d %d %d\n",u,v,weight);
      insertadjver(u,v,weight);
		}
    fscanf(fptr, "%d", &start);
    printf("%d\n",start);
	}
  fclose(fptr);
}



void insertadjver(int src,int des, int weight)  //src is source vertex and des is destination vertex/////////////////////////////////////////////////
{
    adjlistnode *p,*q;

    q=newadjlistnode(des, weight);

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




adjlistnode *newadjlistnode(int vertex, int weight)///////////////////////////////////////////////////////////////////////////////////
{
	adjlistnode *p;
	p = (adjlistnode *)malloc(sizeof(adjlistnode));
	p->vertex = vertex;
	p->weight = weight;
	p->next = NULL;
	return(p);
}



heapnode *newheapnode(int vertex, int dist)///////////////////////////////////////////////////////////////////////////////////
{
	heapnode *p;
	p = (heapnode *)malloc(sizeof(heapnode));\
	p->vertex = vertex;
	p->dist = dist;
	return(p);
}



heap *Buildheap(int maxsize)///////////////////////////////////////////////////////////////////////////////////
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->currentsize = 0;
    h->maxsize = maxsize;
    h->pos = (int *)malloc(maxsize*sizeof(int));
    h->array = (heapnode **)malloc(maxsize*sizeof(heapnode *));
	return(h);
}



void dijkstra(int start)///////////////////////////////////////////////////////////////////////////////////
{
	int i;
	heap *h = Buildheap(V);
	for(i = 0; i<V; i++)
	{
		h->array[i]= newheapnode(i,dist[i]);
		h->currentsize++;
		h->pos[i] = i;
	}
	dist[start] = 0;
	printf("currentsize = %d\n", h->currentsize);
	decreaseKey(h, start, dist[start]);

	while(h->currentsize!=0)
    {
        heapnode* tempheapnode = extractMin(h);
        int u = tempheapnode->vertex;
		printf("u = %d\n", u);
        adjlistnode *p = head[u];
		//printf("dist[u] = dist[%d] = %d\n", u, dist[u]);
        while (p!= NULL)
        {
            int v = p->vertex;
			printf(" (u,v) = (%d,%d), weight = %d \n",u, v,p->weight);
            if (dist[u] != INT_MAX && p->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + p->weight;//updating dist value
                decreaseKey(h, v, dist[v]);//recursive calling decreaseKey this adjacent vertex
            }
            p= p->next;
        }
    }
}



void decreaseKey(heap* h, int v, int dist)//decrease the value of node and hence shifting it////////////////////////////////////////////////////////
{
    int i = h->pos[v];
    h->array[i]->dist = dist;
    while (i && h->array[i]->dist < h->array[(i - 1) / 2]->dist)//shift up the node v up in heap and updating its position(in heap position array) and address(in heap address array)
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



heapnode *extractMin(heap *h)///////////////////////////////////////////////////////////////////////////////////
{
    heapnode *minHeapnode, *lastHeapnode;
    minHeapnode = h->array[0]; //topmost node is the minimum
	lastHeapnode = h->array[h->currentsize-1];//last node i.e currentsize-1(since heap starting with 0)
	printf("min v = %d, last v = %d \n", minHeapnode->vertex,lastHeapnode->vertex);
	h->array[0] = minHeapnode;

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
	if (child != h->currentsize && (h->array[child+1])->dist < (h->array[child])->dist) //gives the minimum child of now
  	{
  	  child++;
  	}

  	if((h->array[now])->dist > (h->array[child])->dist)//if heap[now] is greater(i.e unfit) than minimum child
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
