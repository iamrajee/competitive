#include<bits/stdc++.h> 
using namespace std;

int V,E,u,v;
vector < vector <int>  > adj;
vector<bool> vis;
vector<bool> visinout;


void dfs(int u){
	vis[u] = 1;
    visinout[u] = 1;
    cout<<u<<endl;
	for (auto it:adj[u]){
		if (vis[it] == 0){
			dfs(it);
        }else{
            if(visinout[it]==1){
                cout<<"cycle present"<<endl;
            }
        }
    }
    visinout[u] = false;
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	vis.resize(V,0);
    visinout.resize(V,0);
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
	    // adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){ //we call on whole graph to deal with unconnected graph
	    if(vis[i]==0){
            dfs(i);
        }
    }
    
    return 0;
}