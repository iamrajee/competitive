/*wrong ans, satisfing only test sample ddddddcase*/
#include<bits/stdc++.h>

using namespace std;
long long int n,m,turn;
long long int p1,p2,d,p1old,p2old,turnold,mold;
void store(){
    p1old=p1;
    p2old=p2;
    turnold=turn;
    mold=m;
}
void restore(){
    p1=p1old;
    p2=p2old;
    turn=turnold;
    m=mold;
}
void funA(){
    turn++;
    // cout<<p1<<" "<<p2<<endl;
    // cout<<"---------------"<<p1%p2<<","<<p2%p1<<endl;
    if (p1>p2){
        m = p1%p2;
        store();
        p1 = m;
        if (m!=0){
            // funA();
            // if(turn%2==1){
            if(p2%p1 ==0){
                d = (p1old - m)/p2old;
                if(d!=1){
                    // restore();
                    p1 = p2old*(d-1)+m;
                    // funA();
                }
            }
            // restore();
            funA();
        }
    }else{
        m = p2%p1;
        store();
        p2 = m;
        if (m!=0){
            // cout<<"->"<<m<<","<<p2<<","<<p1<<endl;
            // cout<<"->"<<m<<","<<p1<<","<<p2<<","<<d<<endl;
            // funA();
            if(p1%p2 ==0){
                d = (p2old - m)/p1;
                if (d!=1){
                    // restore();
                    p2 = p1*(d-1)+m;
                    // funA();
                }
            }
            funA();
        }
    }
}
int main() 
{   
    cin >>n;
    // cout<<n<<endl;
    for(int i = 0;i<n;i++){
        cin>>p1>>p2;
        turn = -1;
        funA();
        if (turn%2==0){
            cout<<"Ari"<<endl;
        }else{
            cout<<"Rich"<<endl;
        }
    }
    return 0;
}