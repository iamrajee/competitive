#include<bits/stdc++.h>
using namespace std;

int i,j;
string w,c;
stack <char> st;
int flag;
int wi;
int ci;
int main(){
    while(cin>>w>>c){
        // cout<<w<<" "<<c<<endl;
        cout<<"["<<endl;
        for(i=(1<<2*(int)w.size()); i>-1;--i){
            flag=0;
            wi=0;
            ci=0;
            st = stack <char> ();
            for(j=2*(int)w.size()-1;j>-1;j--){
                
                if(i&(1<<j)){
                    if(wi==(int)w.size()){
                        flag=1;
                        break;
                    }else{
                        st.push(w[wi]);
                        wi++;
                    }
                }else if(!st.empty() && st.top()==c[ci]){
                    st.pop();
                    ci++;
                }else{
                    flag=1;
                    break;
                }
            }
            if(!flag){
                j=2*(int)w.size()-1;
                if(i&(1<<j)){
                    cout<<"i";
                }else{
                    cout<<"o";
                }
                for(j=2*(int)w.size()-2;j>-1;j--){
                    if(i&(1<<j)){
                        cout<<" i";
                    }else{
                        cout<<" o";
                    }
                }
                cout<<endl;
            }

        }
        cout<<"]"<<endl;
    }
    return 0;
}