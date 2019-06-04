#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
string s;
vector <stack<char> > v;
// stack <char> st;
int idx;
int main(){
    cin>>s;
    while(s!="end"){
        cout<<s<<endl;
        idx=1;
        v.push_back(stack<char>());
        for(i=0; i<(int)s.size();i++){
            for(j=0;j<idx;j++){

            }
            v[idx].push(s[i]);
        }
        cin >>s;
    }
    return 0;
}