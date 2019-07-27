#include<bits/stdc++.h> 
using namespace std;

vector < vector <int>  > adj;
vector<bool> visited;

void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFS(int u){
	visited[u] = true;
	cout << u << " ";
	for (int i=0; i<adj[u].size(); i++){
		if (visited[adj[u][i]] == false){
			DFS(adj[u][i]);
        }
    }
}

int main(){
    adj.resize(5);
	visited.resize(5,0);
	addEdge(0, 1);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(3, 4);
	DFS(3);
    return 0;
}