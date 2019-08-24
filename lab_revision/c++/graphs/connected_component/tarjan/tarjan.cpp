#include<bits/stdc++.h> 
using namespace std;

int V,E,u,v;
vector < vector <int>  > adj;
vector < vector <int>  > adj2;
vector<bool> vis;
stack <int> stk;

void topo(int u){
	vis[u] = true;
	// cout << u << " ";
	for (auto it:adj[u]){
		if (vis[it] == false){
			topo(it);
        }
    }
    stk.push(u);
}

void dfs(int u){
	vis[u] = true;
	cout << u << " ";
	for (auto it:adj2[u]){
		if (vis[it] == false){
			dfs(it);
        }
    }
    // stk.push(u);
}

int main(){
    cin>>V>>E;
    adj.resize(V);
    adj2.resize(V);
	vis.resize(V,0);
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
	    // adj[v].push_back(u); //
        adj2[v].push_back(u);
    }
    for(int i=0;i<V;i++){
	    if(vis[i]==0){
            topo(i);
        }
    }

    vis.assign(V,0);//reset vis flags
    while(!stk.empty()){
        u=stk.top();
        // cout << u << " ";
        if(vis[u]==0){
            dfs(u);
        }
        cout<<endl;
        stk.pop();
    }
        
    return 0;
}