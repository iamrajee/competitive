#include<bits/stdc++.h>
using namespace std;

int i,j,k,t,t2,t3;
int n,m,c,r,f;
vector <int> v;
set <int> s;
// /*
void fn(int k_, int n_, int c_){
    // v.push_back(k_);
    if(n_<0 || f==1){//bad
        // return;
    }else if(n_== 0){//oneway
        // k_
        // c_++;
        v.push_back(k_);
        // cout<<" "<<k_;
        s.insert(c_+1);
        // return;
        f=1;
    }else{//many
        
        if(k_!=0){
            v.push_back(k_);
            // cout<<" "<<k_;
            for(j=k_;j>-1 && f==0;j--){
                fn(j*2,n_ - j*2,c_+1);
                // cout<<"<-"<<endl;
            }
        }
    }
    

}
// */
int main(){
    cin>>t;
    // cout<<n<<endl;
    for(i=0;i<t;i++){
        cin>>n;
        // if(n%2==0){
        //     cout<<n<<" ";
        //     cout<<"Alas"<<endl;
        // }else{
        //     cout<<n<<" ";
        //     cout<<<<" "<<n/2<<endl;
        // }
        // /*
        s.clear();
        v.clear();
        f=0;
        fn(1,n-1,0);
        // for(auto it:s){
        //     cout<<it;
        // }
        // cout<<endl;

        
        if(s.empty()==1 || n%2==0){
            // cout<<n<<" ";
            cout<<"Alas"<<endl;
        }else
        {
            // cout<<n<<" ";
            // cout<<*s.begin()-1<<" "<<*s.rbegin()-1<<endl;
            cout<<*s.begin()-1<<" "<<n/2<<endl;
            // for(auto it:v){
            //     cout<<it;
            // }
            // cout<<"<-"<<endl;
        }
        //  */
    }
    return 0;
}