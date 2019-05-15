#include<bits/stdc++.h>

using namespace std;
int i,j;
char c,t;
int l;
int flag,flag2;
priority_queue <char> q;
string s;

int main()
{   
    cin>>s;
    while(s!="#"){
        q = priority_queue <char> ();

        // cout<<s<<endl;
        flag = 0;
        l = s.size();
        i = l-1;
        // c = s[l-1];
        for(i=l-2; i>-1; i--){
            if(s[i]<s[i+1]){
                // q.push(s[i]);
                for(j=i;j<l;j++){
                    q.push(s[j]);
                }
                flag2=0;
                for(j=l-1;j>i;j--){
                    t = q.top();
                    q.pop();
                    if (t == s[i]){
                        s[i] = s[j+1];//one just greater than s[i] 
                        s[j+1] = t;
                        t = q.top();
                        q.pop();
                        flag2=1;
                    }
                    s[j] = t;
                }
                if(!flag2){
                    s[i] = s[i+1];
                    s[i+1]=q.top();
                }
                cout<<s<<endl;
                flag = 1;
                break;
            }
            // else{
            //     c = s[i];
            // }
            // i--;
        }
        if(!flag) cout<<"No Successor"<<endl;
        cin>>s;
    }
    return 0;
}