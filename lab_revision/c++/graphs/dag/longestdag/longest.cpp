#include<bits/stdc++.h>
using namespace std;

int i,j;

int V,E,u,v;
typedef pair<int,int> pii;
vector < vector <pii>  > adj;
// priority_queue <pii, vector<pii>, greater<> > pq;
vector<bool> vis;
stack <int> stk;

int src,w,d;
vector <int> dist;

void dfs(int u){    //for topo
	vis[u] = true;
	// cout << u << " ";        //dont print in while going
	for (auto it:adj[u]){
		if (vis[it.first] == false){
			dfs(it.first);
        }
    }
    stk.push(u);                //insead do while leaving
}

void shortest(){

    for(int i=0;i<V;i++){ //dfs_topo
	    if(vis[i]==0){
            dfs(i);
        }
    }

    while(!stk.empty()){
        u = stk.top();
        cout<<u<<endl;
        stk.pop();
        if(dist[u]!=INT32_MAX){
            for(auto it:adj[u]){
                v=it.first;
                w=it.second;
	        	if(dist[v]>(dist[u]+w)){
                    dist[v] = dist[u]+w;
                }
            }
        }
    }
}

int main(){
    cin>>V>>E;
    adj.resize(V);
    vis.resize(V,0);
    dist.resize(V,INT32_MAX);
    while(E--){
        cin>>u>>v>>w;
        adj[u].push_back({v,-w}); //storing negitive
	    // adj[v].push_back({u,w});//for dag only
    }
    cin>>src;
    dist[src]=0;
    cout<<"-----topo_sort------"<<endl;
	shortest();
    cout<<"-----dist------"<<endl;
    for(auto it:dist) cout<<-it<<endl;
    return 0;
}