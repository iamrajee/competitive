#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int t,l,r,q,s;
int n1;

vector <int> v;
// vector <int> v_;
// vector <int> v2;
vector <int> slice1(vector<int> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<int> vec(first, last);
    return vec;
}

int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    cin>>q;
    for(i=0;i<q;i++){
        sum=0;
        cin>>l>>r;
        vector<int> v_ = slice1(v, l-1, r-1);
        // cout<<"\n----------------";
        // for(auto it:v_){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // vector <int> v_;
        // v_.assign(v.begin(),v.end());
        n1=r-l+1;
        while(n1!=1){
            
            vector<int> v2;
            v2.clear();
            j=0;
            while(j<n1-1){
                v2.push_back((v_[j]+v_[j+1])%10);
                if(v_[j]+v_[j+1]>9){
                    sum++;
                }
                j+=2;
                // cout<<sum<<endl;
            }
            n1/=2;
            // vector<int> v_;
            v_.clear();
            // cout<<v_.size()<<" -"<<l;
            v_.assign(v2.begin(),v2.end());
            // cout<<sum<<" ";
            // cout<<v_.size()<<" "<<v2.size()<<endl;
            // for(auto it:v_){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}