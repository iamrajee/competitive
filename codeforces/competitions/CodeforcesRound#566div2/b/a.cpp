#include<bits/stdc++.h>
using namespace std;

int i,j,h,w,n,sum,k;
int flag=0;
// int s=0;
char c;
vector <vector<int> > v;
vector <int> s(4,0);

void fn(int i, int j){
    s={0,0,0,0};
    if(i>1&&v[i-1][j]=='*'){
        s[1]=1;
    }
    if(j>1&&v[i][j-1]=='*'){
        s[2]=1;
    }
    if(i<h-1&&v[i+1][j]=='*'){
        s[3]=1;
    }
    if(j<w-1&&v[i][j+1]=='*'){
        s[0]=1;
    }
    sum = s[0]+s[1]+s[2]+s[3];
}
int main(){
    cin>>h>>w;
    // cout<<h<<w<<endl;

    for(i=0;i<h;i++){
        v.push_back(vector<int>());
        for(j=0;j<w;j++){
            cin>>c;
            // cout<<c;
            v[i].push_back(c);
        }
        cout<<endl;
    }

    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            v[i][j];
            if(v[i][j]=='*'){
                fn(i,j);
                if(sum==4){//center
                    for(k=i-1;k>0&&v[k][j];k--){

                    }
                    for(k=i+1;k<h&&v[k][j];k++){

                    }
                    for(k=j-1;k>0&&v[i][k];k--){

                    }
                    for(k=j+1;k<w&&v[i][k];k++){

                    }
                }else if(sum==2){
                    if(s[0]==1&&s[2]==1){

                    }else if(s[1]==1&&s[3]==1){

                    }else{
                        flag=1;
                    }
                }else{
                    flag=1;
                }
            }
            if(flag==1){
                break;
            }
        }
        cout<<endl;
    }

    return 0;
}