#include<bits/stdc++.h>
using namespace std;

int n;
int i,j,k;
long long int sum,p,q,r,a;
set <int> st;
vector <int> v;
set <int> st2;
int main(){
    cin>>n>>p>>q>>r;
    for(i=0;i<n;i++){
        cin>>a;
        st.insert(a);
        v.push_back(a);
    }
    st2.insert(abs(p));
    st2.insert(abs(q));
    st2.insert(abs(r));
    int ele = *st2.rbegin();


    int mn = *st.begin();
    int mx = *st.rbegin();
    int mxi = max_element(v.begin(),v.end())-v.begin();
    int mni = min_element(v.begin(),v.end())-v.begin();
    sum=0;

    if(ele==abs(r)){//p<=abs(r) && q<=abs(r)){   //r
        if(r<0){
            k=mni;
            sum+=mn*r;
        }else{
            k=mxi;
            sum+=mx*r;
        }

        if(abs(p)<abs(q)){
            // cout<<"rqp"<<endl;
            if(q<0){
                auto it = min_element(v.begin(),v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }else{
                auto it = max_element(v.begin(),v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }

            if(p<0){
                auto it = min_element(v.begin(),v.begin()+j+1);
                i=it-v.begin();
                sum+=(*it)*p;
            }else{
                auto it = max_element(v.begin(),v.begin()+j+1);
                i=it-v.begin();
                sum+=(*it)*p;
            }

        }else{
            // cout<<"rpq"<<endl;
            if(p<0){
                auto it = min_element(v.begin(),v.begin()+k+1);
                i=it-v.begin();
                sum+=(*it)*p;
            }else{
                auto it = max_element(v.begin(),v.begin()+k+1);
                i=it-v.begin();
                sum+=(*it)*p;
            }

            if(q<0){
                auto it = min_element(v.begin()+i,v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }else{
                auto it = max_element(v.begin()+i,v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }
        }
    }else if(ele==abs(q)){//p<=(q && r<=q){ //q
        if(q<0){
            j=mni;
            sum+=mn*q;
        }else{
            j=mxi;
            sum+=mx*q;
        }
        // cout<<"q.."<<endl;
        if(r<0){
            auto it = min_element(v.begin()+j,v.end());
            k=it-v.begin();
            sum+=(*it)*r;
        }else{
            auto it = max_element(v.begin()+j,v.end());
            k=it-v.begin();
            sum+=(*it)*r;
        }
        if(p<0){
            auto it = min_element(v.begin(),v.begin()+j+1);
            i=it-v.begin();
            sum+=(*it)*p;
        }else{
            auto it = max_element(v.begin(),v.begin()+j+1);
            i=it-v.begin();
            sum+=(*it)*p;
        }
    }else{  //p
        if(p<0){
            i=mni;
            sum+=mn*p;
        }else{
            i=mxi;
            sum+=mx*p;
        }

        if(abs(r)<abs(q )){
            // cout<<"pqr"<<endl;
            if(q<0){
                auto it = min_element(v.begin()+i,v.end());
                j=it-v.begin();
                sum+=(*it)*q;
            }else{
                auto it = max_element(v.begin()+i,v.end());
                j=it-v.begin();
                sum+=(*it)*q;
            }

            if(r<0){
                auto it = min_element(v.begin()+j,v.end());
                k=it-v.begin();
                sum+=(*it)*r;
            }else{
                auto it = max_element(v.begin()+j,v.end());
                k=it-v.begin();
                sum+=(*it)*r;
            }

        }else{
            // cout<<"prq"<<endl;
            if(r<0){
                auto it = min_element(v.begin()+i,v.end());
                k=it-v.begin();
                sum+=(*it)*r;
            }else{
                auto it = max_element(v.begin()+i,v.end());
                k=it-v.begin();
                sum+=(*it)*r;
            }

            if(q<0){
                auto it = min_element(v.begin()+i,v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }else{
                auto it = max_element(v.begin()+i,v.begin()+k+1);
                j=it-v.begin();
                sum+=(*it)*q;
            }
        }

    }
    cout<<sum<<endl;
    // cout<<sum<<" : "<<i<<j<<k<<endl;
    
    return 0;
}