#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) { 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited){ // A utility function to do DFS of graph recursively from a given vertex u. 
	visited[u] = true; 
	cout << u << " "; 
	for (int i=0; i<adj[u].size(); i++){
		if (visited[adj[u][i]] == false){ 
			DFSUtil(adj[u][i], adj, visited);
        }
    }
} 

void DFS(vector<int> adj[], int V) { // This function does DFSUtil() for all unvisited vertices.
	vector<bool> visited(V, false); 
	for (int u=0; u<V; u++){
		if (visited[u] == false){
			DFSUtil(u, adj, visited);
        }
    }
} 

int main() 
{ 
	vector<int> adj[5];
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	DFS(adj, 5); 
	return 0;
}