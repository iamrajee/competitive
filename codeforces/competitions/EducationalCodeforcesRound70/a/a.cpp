#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum;
int a,b,c,d,t,x,y,xn,yn;
string xs,ys;
char ch;
string s;

vector <int> v;
set <int> st;
multiset <int> ms;
queue <int> q;
priority_queue <int> pq;
map <int,int> mp;

int xi,yi;
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>xs;
        cin>>ys;
        int xn = (int)xs.size();
        int yn = (int)ys.size();

        for(xi=xn-1; xi>-1; xi--){
            if(xs[xi]=='1'){
                break;
            }
        }

        for(yi=xi; yi>-1; yi--){
            if(ys[yi]=='1'){
                break;
            }
        }

        yi-xi+yn;

        s=xs.substr(min(xi+1,xn-1),xn);

        int carry=0;
        string ts;
        for(i=xi; i<xn && i<yn; i--){
            if(xs[i]=='1' && ys[i]=='1'){
                if(carry==0){

                }
            }else if(xs[i]=='0' && ys[i]=='0'){
                
            }else{

            }
        }
    }
    return 0;
}