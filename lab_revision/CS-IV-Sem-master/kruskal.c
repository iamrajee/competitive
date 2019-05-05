/*
Name - Rajendra singh
Roll no. 111601017
Question - Kruskal Alogrithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct edgenode//structure for edgenode
{
   int src;
   int des;
   int weight;
}edgenode;
edgenode *edgearray[200];//to store input graph
edgenode *mst[200];//to store mst

typedef struct heapnode//structure for heapnode
{
  int src;
  int des;
  int weight;
}heapnode;
heapnode *newheapnode(edgenode *);

typedef struct heap//heap structure
{
    int currentsize;      //current size of heap
    int maxsize;  // maximum size of heap of min heap
    struct heapnode **edgeheaparray;  //ptr to the array of address(ptr to node) of heapnode in the array
}heap;


int V; //no. of vertices
int E; //no. of edges
int start;
int parent[200];
int rank[200];

//FUNTION DECLARATION
void init();
void readfile();
void insertadjver(int, int ,int , int );
heap *Buildheap(int );
void swap(heapnode **, heapnode **);
heapnode *extractMin(heap *);
void minHeapify(heap *, int );
void makeset(int);
int find(int );
int Union(int,int);
void kruskal();
edgenode *newedgenode(int , int , int );

//MAIN FUNCTION
int main()/////////////////////////////////////////////////////////////////////////////////////////
{
	  int i;
    init();//INITIALISATION
    readfile();//READ FILE FROM TERMINAL
    kruskal();//Kruskal FUNCTION CALLED

    printf("\n\nMST IS: \n" );//PRINTING MST
    int weightsum =0;
    for (i = 0; i < V-1; i++)
    {
      weightsum = weightsum + mst[i]->weight;
      printf("edge = (%d,%d), edge weight = %d \n",mst[i]->src, mst[i]->des,mst[i]->weight);
    }
    printf("\nAND WEIGHT OF MST IS : %d\n**************************************\n", weightsum);
    return 0;
}

//Kruskal FUNCTION
void kruskal()///////////////////////////////////////////////////////////////////
{
  int i, u;
  heap *h = Buildheap(E);//building heap with 0 element adding then node 1 by 1 by copying form edgenode
  for (i = 0; i < V; i++)//makeset for all vertices
  makeset(i);
  int e = 1;
  while (e < V)//extractMin AND Union until we didn't get V-1 edges in MST
  {
    heapnode *p = extractMin(h);

    if(Union(p->src, p->des) == 1)
    {
      mst[e-1] = newedgenode(p->src, p->des, p->weight);//e-1, since e starting from 1
      e++;
    }
  }
}

heap *Buildheap(int maxsize)///////////////////////////////////////////////////////////////////////////////////
{
    int i;
	  heap *h = (heap*)malloc(sizeof(heap));
	  h->currentsize = 0;
    h->maxsize = maxsize;
    h->edgeheaparray = (heapnode **)malloc(maxsize*sizeof(heapnode *));
    for(i = 0; i<E; i++)
  	{
      h->edgeheaparray[i]= newheapnode(edgearray[i]);
      h->currentsize++;
  	}

    for (i = (E-1)/2; i >= 0; i--)
    {
      minHeapify(h,i); //minHeapify at all node having child staring form bottom
    }

	  return(h);
}

void minHeapify(heap *h, int now)//heapify all element contected below now///////////////////////////////////////////////////////////////////////////////////
{
  int child;//child node position

  while((now*2+2) <= (h->currentsize))//while right child index is less or equal to heapsize
  {
	  child = now*2 + 1;
	  if (child != h->currentsize && (h->edgeheaparray[child+1])->weight < (h->edgeheaparray[child])->weight) //gives the minimum child of now
  	{
  	  child++;
  	}

  	if((h->edgeheaparray[now])->weight > (h->edgeheaparray[child])->weight)//if heap[now] is greater(i.e unfit) than minimum child
  	{
		  swap(&h->edgeheaparray[now], &h->edgeheaparray[child] );
	  }
	  else
	  {
		    return;
	  }
	  now = child;
  }
}

void makeset(int u)//////////////////////////////////////////////////////////////////////////////////////
{
  parent[u] = u;
  rank[u] = 0;
}


int find(int u)//////////////////////////////////////////////////////////////////////////////////////
{
  if(parent[u] != u)
  {
    u = parent[u];
    parent[u] = find(u);/////////////////////??????
  }
  return(u);
}

int Union(int u, int v)////////////////////////////////////////////////////////
{
  int x,y;
  x = find(u);
  y = find(v);
  //printf("x = %d,y = %d\n", x, y);
  if(x == y)
  {
    return(0);
  }
  if(rank[x] > rank[y])
  {
    parent[y] = x;
  }
  else if(rank[x] < rank[y])
  {
    parent[x] = y;
  }
  else//when both rank equal
  {
    parent[y] = x;
    rank[x]++;
  }
  return(1);
}

//FUNTION FOR INITIALISATION
void init()//////////////////////////////////////////////////////////////////////////////////////
{
	int i;
	for (i = 0; i < V; i++)
	{
    	edgearray[i] = NULL;
	 }
}

void readfile()///////////////////////////////////////////////////////////////////////////////////
{
    int u, v, weight;
	  int success,r,w;
	  int i = 0;
    printf("\n**************************************\nGRAPH IS :\n" );
		scanf("%d", &V);//reading no. vertex
		printf("\n%d\n",V);
    scanf("%d", &E);//reading no. edge
		printf("%d\n",E);

		for(i=0; i<E; i++)
		{
      scanf("%d", &u);
      scanf("%d", &v);
      scanf("%d", &weight);
      printf("%d %d %d\n",u,v,weight);
      insertadjver(i,u,v,weight);
		}
}



void insertadjver(int i, int src,int des, int weight)  //src is source vertex and des is destination vertex/////////////////////////////////////////////////
{
     edgearray[i] = newedgenode(src, des, weight);// (i)th edge
  }


edgenode *newedgenode(int src, int des, int weight)///////////////////////////////////////////////////////////////////////////////////
{
	edgenode *p;
	p = (edgenode *)malloc(sizeof(edgenode));
	p->src = src;
  p->des = des;
	p->weight = weight;
	// p->next = NULL;
	return(p);
}



heapnode *newheapnode(edgenode *q)///////////////////////////////////////////////////////////////////////////////////
{
	heapnode *p;
	p = (heapnode *)malloc(sizeof(heapnode));
	p->src    = q->src;
  p->des    = q->des;
	p->weight = q->weight;
	return(p);
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
    minHeapnode = h->edgeheaparray[0]; //topmost node is the minimum
	lastHeapnode = h->edgeheaparray[h->currentsize-1];//last node i.e currentsize-1(since heap starting with 0)
  // printf("heap bfr extractMin is:" );
  // for (int i = 0; i < h->currentsize; i++) {
  //   printf("%d\t", h->edgeheaparray[i]->weight);
  // }
  // printf("\n");
  h->edgeheaparray[0] = lastHeapnode;
	h->currentsize--;//reducing the currentsize

	minHeapify(h,0);//calling the minHeapify at starting node
  // printf("heap aftr extractMin is: ");
  // for (int i = 0; i < h->currentsize; i++) {
  //   printf("%d\t", h->edgeheaparray[i]->weight);
  // }
  // printf("\n");
    return(minHeapnode);
}
/*
SAMPLE INPUT GRAPH :

4
5
0 1 2
0 3 7
1 2 10
1 3 3
2 3 8

*/
