                                                                                                                                                                                                                                                                                                                                        #include<bits/stdc++.h>
using namespace std;

int i,j;

int V,E,u,v;
typedef pair<int,int> pii;
vector < vector <pii>  > adj;
vector<bool> vis;
priority_queue <pii, vector<pii>, greater<> > pq;

int src,w,d;
vector <int> dist;

void prims(){
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        u = pq.top().second;//nearest neighbour from all visited
        vis[u]=1;//only here
        cout<<u<<endl;
        pq.pop();
        for(auto it:adj[u]){
            v=it.first;
            w=it.second;
	    	if(dist[v]>w && vis[v]==0){ //nearest neighbour from now visited
                dist[v]=w;
                //vis[v]=1;//not here
                pq.push({dist[v],v});
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
        adj[u].push_back({v,w});
	    adj[v].push_back({u,w});
    }
    cin>>src;
	prims();
    return 0;
}