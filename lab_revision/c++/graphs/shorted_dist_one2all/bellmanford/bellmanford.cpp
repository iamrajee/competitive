#include<bits/stdc++.h>
using namespace std;

int i,j,k;
int V,E,u,v;
typedef pair<int,int> pii;
vector < vector <pii>  > adj;
int src,w,d;
vector <int> dist;

void bellmanford(){
    dist[src]=0;
    for(i=0; i<V-1; i++){//V-1 round
        for(u=0; u<V; u++){//all vertex
            for(auto it:adj[u]){
                v = it.first;
                w = it.second;
                dist[v] = min(dist[v], dist[u]+w);
            }
        }
    } 
    for(u=0; u<V; u++){
        for(auto it:adj[u]){
            v = it.first;
            w = it.second;
            if(dist[v] > dist[u] + w) {//if thier thier are any further changes which it must had negitive cycles!!!
              cout<<"Negative Cycle exists!!"<<endl;
              return;
            }
        }
    }
}

int main(){
    cin>>V>>E;
    adj.resize(V);
    dist.resize(V,INT32_MAX);
    while(E--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
	    adj[v].push_back({u,w});
    }
    cin>>src;
	bellmanford();
    for(auto it:dist) cout<<it<<endl;
    return 0;
}