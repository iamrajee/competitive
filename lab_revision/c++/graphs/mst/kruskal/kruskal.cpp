#include<bits/stdc++.h>
using namespace std;

int i,j,k;

int V,E,u,v,w;
long long int wsum;
vector <int> root;
typedef pair<int, int> pii;
//priority_queue < pair<long long, pii> > edgespq; //usaually increasing
priority_queue <    pair<long long, pii>,   vector <pair<long long, pii> >,   greater <>     > edgespq; //greater => decreasing

int findroot(int x){
    while(root[x] != x){
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}

void union1(int u, int v){
    int p = findroot(u);
    int q = findroot(v);
    root[p] = root[q];
}

void kruskal(){
    wsum = 0;
    while(!edgespq.empty()){
        auto it = edgespq.top();
        u = it.second.first;
        v = it.second.second;
        w = it.first;
        edgespq.pop();
        if(findroot(u) != findroot(v))//i.e disjoint
        {
            wsum += w;
            union1(u,v);
            cout<<u<<" "<<v<<endl;
        }    
    }
}

int main(){
    cin>>V>>E;
    root.resize(V);
    for(i=0;i<V;i++) root[i]=i; //self root

    while(E--){
        cin>>u>>v>>w;
        edgespq.push({w, {u, v}});
    }
    kruskal();
    cout << wsum << endl;
    return 0;
}