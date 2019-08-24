#include<bits/stdc++.h> 
using namespace std;

int V,E,u,v;
vector < vector <int>  > adj;
vector<bool> vis;

void dfs(int u){
	vis[u] = true;
	cout << u << " ";
	for (auto it:adj[u]){
		if (vis[it] == false){
			dfs(it);
        }
    }
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	vis.resize(V,0);
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
	    adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){ //we call on whole graph to deal with unconnected graph
	    if(vis[i]==0){
            dfs(i);
        }
    }
        
    return 0;
}