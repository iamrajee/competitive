#include<bits/stdc++.h>

using namespace std;
int n;
long int x,y;
int T,t,i,j;
vector <vector <int> > v;
int main()
{   
    cin >>T;
    cout<<T<<endl;
    for(i = 0;i<T;i++){
        cin >>n;
        cout<<n<<endl;
        v.clear();
        v.push_back(vector <int>());
        for(j = 0;j<n;j++){
            cin >>x>>y;
            cout<<x<<" "<<y<<endl;
            v[i].push_back(x);
            v[i].push_back(y);

            v[i].push_back(-x);
            v[i].push_back(y);

            // v[i].push_back(0);
        }
    }
    return 0;
}