#include<bits/stdc++.h>
using namespace std;
int V,E,u,v;
vector < vector <int>  > adj;
vector<bool> vis;
queue <int> q;

void bfs(int u){
    // if(vis[u]==1){
    //     return;    
    // }
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop();
        for(auto it:adj[u]){
	    	if(vis[it]==0){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	vis.resize(V,0);
    while(E--){ //reading list of edge to create adjlist
        cin>>u>>v;
        adj[u].push_back(v);
	    adj[v].push_back(u);
    }
    for(int i=0;i<V;i++) //we call on whole graph to deal with unconnected graph
        if(vis[i]==0)
	        bfs(i);
    return 0;
}