#include<bits/stdc++.h>
using namespace std;

int n,i,j,t,ac,ic,ec,oc,uc,sum;
string s;
// int flag1,flag2;
// long int zeroes;
vector <int> v;
// set <int> s;
// map <int,int> m;
vector <char> vw = {'a','e','i','o','u'};

int main(){
    cin>>n;
    cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>s;
        cout<<s<<endl;
        sum=0;
        for(i=0;i<5;i++){
            sum+=count(s.begin(),s.end(),'a');
        }
        v.push_back(sum);
    }
    return 0;
}