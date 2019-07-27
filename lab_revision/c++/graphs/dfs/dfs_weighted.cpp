#include<bits/stdc++.h> 
using namespace std;

vector < vector <pair<int,int> >  > adj;
vector<bool> visited;

void addEdge(int u, int v, int w){
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}

void DFS(int u){
	visited[u] = true;
	cout << u << " ";
	for (int i=0; i<adj[u].size(); i++){
		if (visited[adj[u][i].first] == false){
			DFS(adj[u][i].first);
        }
    }
}

int main(){
    adj.resize(5);
	visited.resize(5,0);
	addEdge(0, 1, 10);
	addEdge(0, 4, 20);
	addEdge(1, 2, 30);
	addEdge(1, 3, 40);
	addEdge(1, 4, 50);
	addEdge(2, 3, 60);
	addEdge(3, 4, 70);
	DFS(3);
    return 0;
}