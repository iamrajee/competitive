#include<bits/stdc++.h> 
using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef vector <pii> vii;
typedef vector <vi> vvi;

int V,E,u,v,ctr,root,rootchild;
vvi adj;
vi low,id,parent,ap; //ap:articul. point
// vi vis;//not req.
// stack <int> stk;//not req.

void dfs(int u){
	// vis[u]=1;
    low[u]=ctr;
    id[u]=ctr;
    ctr++;
    // stk.push(u);
	for (auto it:adj[u]){
        int v=it;
        if(id[v]==-1){ //!!! check unvisited with id !not with vis
            parent[v]=u;
            if(u==root) rootchild++;
            // cout<<"vs:"<<v<<endl;
            dfs(v);
            // cout<<"ve:"<<v<<endl;
            if(low[v]>=id[u]){
                ap[u]=1;//wrong ans
                cout<<"u,v,low[v],id[u]:"<<u<<","<<v<<","<<low[v]<<","<<id[u]<<endl;
            }
            //if(low[v]>id[u]) cout<<"bridge:"<<u<<"--"<<v<<endl;//wrong ans????
            
            low[u]=min(low[u],low[v]);
        }else if(v!=parent[u]){
			low[u]=min(low[u],low[v]);
            cout<<"back:u,v"<<u<<","<<v<<endl;
        }
    }
    
}

int main(){
    cin>>V>>E;
    adj.resize(V);
	// vis.resize(V,0);
    low.resize(V,0);
    parent.resize(V,0);
    ap.resize(V,0);
    id.resize(V,-1);
    ctr=0;
    while(E--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<V;i++){
	    if(id[i]==-1){              //!!! check unvisited with id !not with vis
            root=i;
            rootchild=0;
            dfs(i);
            ap[root]=(rootchild>1); //if
        }
    }
    
    cout<<"ap: ";
    for(int i=0;i<V;i++){
	    if(ap[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<low[4]<<endl;
    return 0;
}