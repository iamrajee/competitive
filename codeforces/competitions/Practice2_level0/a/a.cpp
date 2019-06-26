#include<bits/stdc++.h>
using namespace std;

int n;
int i,pos;
string s;
set <string> st;
int main(){
    cin>>n;
    for(i=0;i<n;i++){   
        cin>>s;
        pos = s.find("kh");
        while(pos!=-1){
            s = s.substr(0,pos) + "h" + s.substr(pos+2);
            pos = s.find("kh");
        }
        pos = s.find("oo");
        while(pos!=-1){
            s = s.substr(0,pos) + "u" + s.substr(pos+2);
            pos = s.find("oo");
        }
        pos = s.find("ou");
        while(pos!=-1){
            s = s.substr(0,pos) + "uo" + s.substr(pos+2);
            pos = s.find("ou");
        }
        // cout<<s2<<" "<<s<<" "<<endl;
        st.insert(s);       
    }
    cout<<(int)st.size()<<endl;
    return 0;
}