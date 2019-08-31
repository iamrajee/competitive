#include<bits/stdc++.h> 
using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef vector <pii> vii;
typedef vector <vi> vvi;

int V,E,u,v,ctr,scc;
vvi adj;
vi low,id,vis;
stack <int> stk;

void dfs(int u){
	vis[u]=1;
    low[u]=ctr;
    id[u]=ctr;
    ctr++;
    stk.push(u);
	for (auto it:adj[u]){
        v=it;
        if(id[v]==-1){ //!!! check unvisited with id !not with vis
            dfs(v);
        }
        
		if(vis[v]==1){ //condition for update (if v was not visited then it will in future so do now)
			low[u]=min(low[u],low[v]);
        }
    }

    if(low[u]==id[u]){ //print scc if this is start of scc
        scc++;
        cout<<"scc"<<scc<<": ";
        while(1){
            v=stk.top();
            stk.pop();
            vis[v]=0;
            cout<<v<<" ";
            if(u==v){
                cout<<endl;
                break;
            }
        }
    }
    
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	vis.resize(V,0);
    low.resize(V,0);
    id.resize(V,-1);
    ctr=0;
    scc=0;//for couting the no. of scc
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
	    // adj[v].push_back(u); //only for directed
    }
    
    for(int i=0;i<V;i++){
	    if(id[i]==-1){              //!!! check unvisited with id !not with vis
            dfs(i);
        }
    }
        
    return 0;
}