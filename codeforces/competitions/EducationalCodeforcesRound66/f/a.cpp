#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t,k,a;
int x,y,y_,yt,l,r;
vector <int> v;
set <int> s;
vector <int>::iterator itrv;
set <int>::iterator itrs;
int b,c;
int main(){
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<t<<" ";
        v.push_back(t);
    }
    c=0;
    for(i=0;i<(int)v.size();i++){
        s.clear();
        cout<<"--"<<endl;
        for(j=i;j<(int)v.size();j++){
            s.insert(v[j]);
            // cout<<
            if(*s.begin()==1 && *(--s.end())==j-i+1){
                for(auto it:s){
                    cout<<it<<" ";
                }
                cout<<" => "<<s.size()<<endl;
                c++;
            }else if((int)s.size()!=j-i+1){
                break;
            }
            // ++s.end();
        }
        // c+=(j-i+1);
    }

    cout<<c<<endl;
    return 0;
}