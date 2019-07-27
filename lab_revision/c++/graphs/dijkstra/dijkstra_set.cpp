#include<bits/stdc++.h>
using namespace std;

int i,j;

int V,E,u,v;
vector < vector <pair<int,int> >  > adj;
vector<bool> vis;
priority_queue <pair<int,int> > pq;

int src,w,d;
vector <int> dist;

void dijkstra(int src){
    dist[src] = 0;
    vis[src] = 1;
    pq.push({0,src});
    while(!pq.empty()){
        u = pq.top().second;
        d = pq.top().first;
        pq.pop();
        for(auto it:adj[u]){
	    	if(vis[it.first]==0){
                vis[it.first] = 1;
                pq.push({d+it.second,it.first});
            }
        }
    }
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	vis.resize(V,0);
    dist.resize(V,0);
    src=0;
    while(E--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
	    adj[v].push_back({u,w});
    }
	dijkstra(src);
    for(auto it:dist) cout<<it<<endl;
    return 0;
}