#include<bits/stdc++.h>

using namespace std;
int n,t,i,j,temp;
//vector - not sorted
//pq - cant get first or smallest ele
//simple set no duplication set
multiset<int> ms;
multiset <int, greater <int> > :: iterator itr;

void reduce(){
    temp = *ms.begin() + *++ms.end() + ((*ms.begin())   *   (*++ms.end()));
    // cout<<", temp="<<temp<<", begin="<<*ms.begin()<<", end="<<*++ms.end()<<endl;
    ms.erase(ms.begin());
    ms.erase(--ms.end());
    ms.insert(temp);
}
void printset(){
    cout<<"\n=>";
    for (itr = ms.begin(); itr != ms.end(); ++itr){ cout << '\t' << *itr; }
    // cout<<endl;
}
int main()
{   
    cin >>n;
    // cout<<n<<endl;
    for(i = 0;i<n;i++){
        ms.clear();
        cin>>t;
        // cout<<"\n*******************"<<t<<"**********************";
        // priority_queue <int> pq;

        for(j=0;j<t;j++){
            ms.insert(j+1);
        }

        // printset();
        while(ms.size()!=1){
            reduce();
            // printset();
        }
        cout<<*ms.begin()<<endl;
    }
    return 0;
}