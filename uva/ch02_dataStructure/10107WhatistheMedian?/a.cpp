#include<bits/stdc++.h>

using namespace std;
int n,t,s,i,j,k;
int med;
multiset <int> ms;
// multiset<int>::iterator it = my_set.begin();
multiset <int>:: iterator itr = ms.begin();
void f(){
    
}

int main()
{   
    
    while(cin>>t){
        // cout<<t<<"  ";
        ms.insert(t);
        s = ms.size();
        itr = ms.begin();
        if(s%2){
            advance(itr, (s-1)/2);
            med = *itr;
            cout<<med<<endl;
        }else{
            advance(itr, s/2);
            med = *itr;
            // cout<<med<<" ";
            --itr;
            med += *itr;
            // cout<<*itr<<" ";
            med = med/2;
            cout<<med<<endl;
        }
    }
    return 0;
}