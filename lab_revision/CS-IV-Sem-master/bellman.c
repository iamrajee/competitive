/*
NAME - RAJENDRA SINGH
ROLL NO.- 111601017
PROGRAM: Bellman–Ford Algorithm
*/

#include<stdio.h>
#include<stdlib.h>///for malloc
#include<string.h>
#include <limits.h>//for INT_MAX

//all structures
typedef struct edgenode// a structure to represent a weighted edge in graph
{
    int src, dest, weight;
}edgenode;


typedef struct Graph// a structure to represent a connected, directed and  weighted graph
{
    int V, E;
    struct edgenode** edge;
}Graph;

//global variable
int start;

//function DECLARATION
Graph* readfile();
Graph* createGraph(int, int);
Graph* readfile();
void BellmanFord(Graph*);
edgenode *newedgenode();



//main function
int main()///////////////////////////////////////////////////////////////
{
  Graph* graph = readfile();
  BellmanFord(graph);//at start vertex
}


//function to find all dist form start vertex to all other and also if there is -ve weighted cycle(cycle whose sum total of all edges is -ve)
void BellmanFord( Graph* graph)////////////////////////////////////////////////
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];


    for (int i = 0; i < V; i++)//initialise all dist to INT_MAX
        dist[i]   = INT_MAX;
    dist[start] = 0;



    for (int i = 1; i <= V-1; i++)//V-1 rounds
    {
        for (int j = 0; j < E; j++)//for all edges update distance
        {
            int u = graph->edge[j]->src;
            int v = graph->edge[j]->dest;
            int weight = graph->edge[j]->weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])//dist != INT_MAX, since in that case will update to ~ INT_MAX
                dist[v] = dist[u] + weight;//updating dist
        }
    }



    //if there are no negative cycle, then after above loop(V-1 rounds) we are guaranteed to get minimum dist of all vertices
    //but if run the same above loop once more(1 more round), and if get a shorted path this will imply negative edge cycle
    for (int j = 0; j < E; j++)
    {
        int u = graph->edge[j]->src;
        int v = graph->edge[j]->dest;
        int weight = graph->edge[j]->weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("\n*******Graph has negative weighted cycle**************8\n");
    }


    //PRINTING distances
    printf("\n\nDistance of the all vertices from start vertex is as follow:\n\n");
    printf("(start,vertex) \t\t dist[vertex]\n");
    for (int i = 0; i < V; ++i)
        printf("(%d,%d) \t\t\t %d\n",start, i, dist[i]);
    printf("******************************************************\n" );
    return;
}

//function to read graph from file directed terminal
Graph* readfile()///////////////////////////////////////////////////////////////////////////////////
{
    int V,E, u, v, weight,i;

    printf("\n************************************************\nGRAPH IS :\n" );
		scanf("%d", &V);//reading no. vertex
		printf("\n%d\n",V);
    scanf("%d", &E);//reading no. edge
		printf("%d\n",E);

    Graph* G = createGraph(V,E);

    //edgenode *p = G->edge;

		for(i=0; i<E; i++)
		{
      scanf("%d", &u);
      scanf("%d", &v);
      scanf("%d", &weight);
      printf("%d %d %d\n",u,v,weight);
      G->edge[i]->src = u;
      G->edge[i]->dest = v;
      G->edge[i]->weight = weight;
      //insertadjver(i,u,v,weight);
		}
    scanf("%d", &start);
    printf("%d\n",start );
    return(G);
}



// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)///////////////////////////////////////////////////////////
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (edgenode**)malloc(E*sizeof(edgenode*));
    for(int i = 0; i<E; i++)
  	{
      graph->edge[i] = newedgenode();
  	}
    return graph;
}

//newedgenode function
edgenode *newedgenode()////////////////////////////////////////////////////
{
  edgenode *p = (edgenode *)malloc(sizeof(edgenode));
  p->src = 0;
  p->dest = 0;
  p->weight = 0;
  return(p);
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
0

*/
