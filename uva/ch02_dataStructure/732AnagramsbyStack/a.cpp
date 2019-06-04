#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
vector <int> v;
string s1,s2;
stack <char> st;
queue <char> q;
int main(){
    while(cin>>s2>>s1){
        cout<<s1<<" "<<s2<<endl;
        j=0;
        cout<<"["<<endl;
        for(i=0;i<(int)s2.size();i++){
            if(s2[i]==s1[j]){
                // cout<<"i o ";
                q.push('i');
                q.push('o');
                j++;
            }else{
                if(!st.empty()){
                    if(st.top()==s1[j]){
                        st.pop();
                        // cout<<"o i ";
                        q.push('o');
                        q.push('i');
                        j++;
                    }else{
                        // cout<<"i ";
                        st.push(s2[i]);
                        q.push('i');
                    }
                }else{
                    // cout<<"i ";
                    st.push(s2[i]);
                    q.push('i');
                }
            }
        }
        while(!st.empty()){
            if(st.top()==s1[j]){
                st.pop();
                // cout<<"o ";
                q.push('o');
                j++;
            }else{
                break;
            }
        }
        if(j==(int)s2.size()){
            while(!q.empty()){
                cout<<q.front()<<" ";
                q.pop();
            }
        }
        cout<<"\n]"<<endl;
    }
    return 0;
}