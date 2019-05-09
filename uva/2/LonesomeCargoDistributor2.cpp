/*wrong ans, satisfing only test sample ddddddcase*/
#include<bits/stdc++.h>

using namespace std;
long long int n,m;
int p1,p2,d,p1old,p2old;
int turn;
void funA(){
    turn++;
    // cout<<p1<<" "<<p2<<endl;
    // cout<<"---------------"<<p1%p2<<","<<p2%p1<<endl;
    if (p1>p2){
        m = p1%p2;
        p1old=p1;
        p1 = m;
        if (m!=0){
            d = (p1old - m)/p2;
            if((p1%p2==0 || p2%p1==0)&&d!=1){
                p1 = p2*(d-1)+m;
                // funA();
            }
            funA();
        }
    }else{
        m = p2%p1;
        p2old=p2;
        p2 = m;
        if (m!=0){
            // cout<<"->"<<m<<","<<p2<<","<<p1<<endl;
            
            // cout<<"->"<<m<<","<<p1<<","<<p2<<","<<d<<endl;
            if((p1%p2==0 || p2%p1==0)){
                d = (p2old - m)/p1;
                if (d!=1){
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