#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,counter;
int a,b,t;
char c;
string s1,s2,s3,s;
set <string> st;
int main(){
    cin>>s1>>s2>>s3;
    st.insert(s1);
    st.insert(s2);
    st.insert(s3);
    // cout<<(int)s2[0]-48<<endl;
    int sz=(int)st.size();
    if(sz==1){
        cout<<"0"<<endl;
    }else if(sz==2){
        cout<<"1"<<endl;
    }else{
        s=s1+s2+s3;
        counter=0;
        int mf=0;
        int pf=0;
        int sf=0;
        if(s.find("m") != string::npos){
            mf=1;
        }
        if(s.find("p") != string::npos){
            pf=1;
        }
        if(s.find("s") != string::npos){
            sf=1;
        }
        if(mf+pf+sf==3){
            cout<<"2"<<endl;
        }else if(mf+pf+sf==1){
            s1=*st.begin();
            auto it = st.begin();
            it++;
            s2=*(it);
            s3=*st.rbegin();
            if((int)s3[0]-(int)s1[0]==2){
                cout<<"0"<<endl;
            }else if((int)s3[0]-(int)s2[0]<3 || (int)s2[0]-(int)s1[0]<3){
                cout<<"1"<<endl;
            }else{
                cout<<"2"<<endl;
            }
        }
        else{
            s1=*st.begin();
            auto it = st.begin();
            it++;
            s2=*(it);
            s3=*st.rbegin();

            // cout<<s1<<s2<<s3<<endl;
            // cout<<(int)s3[0]-(int)s1[0]<<endl;
            
            string fs;
            if(count(s.begin(),s.end(),'m')==1){
                fs='m';
            }else if(count(s.begin(),s.end(),'p')==1){
                fs='p';
            }else{
                fs='s';
            }
            if(s1.find(fs) != string::npos && (int)s3[0]-(int)s2[0]<3 ){
                cout<<"1"<<endl;
                // cout<<"hi1"<<endl;
            }else if(s2.find(fs) != string::npos && (int)s3[0]-(int)s1[0]<3){
                cout<<"1"<<endl;
                // cout<<"hi2"<<endl;
            }else if(s3.find(fs) != string::npos && (int)s2[0]-(int)s1[0]<3){
                cout<<"1"<<endl;
                // cout<<"hi3"<<endl;
            }else{
                cout<<"2"<<endl;
            }
            
        }
        

    }
    return 0;
}