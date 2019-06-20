#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int r=0;
priority_queue <int> pq;
int main(){
    cin>>a>>b>>c>>d;
    pq.push(a);
    pq.push(b);
    pq.push(c);

    // cout<<pq.top()<<endl;
    c=pq.top();
    pq.pop();
    b=pq.top();
    pq.pop();
    a=pq.top();

    if(c-b<d){
        r+=d-c+b;
    }
    if(b-a<d){
        r+=d-b+a;
    }
    cout<<r<<endl;
    return 0;
}