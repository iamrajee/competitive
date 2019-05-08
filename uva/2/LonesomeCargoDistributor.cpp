/*wrong ans, satisfing only test sample case*/
#include<bits/stdc++.h>

using namespace std;
int n,p1,p2,m;
int turn;
void funA(){
    turn++;
    // cout<<p1<<" "<<p2<<endl;
    // cout<<"---------------"<<p1%p2<<","<<p2%p1<<endl;
    if (p1>p2){
        m = p1%p2;
        p1 = m;
        if (m!=0){
            funA();
        }
    }else{
        m = p2%p1;
        p2 = m;
        if (m!=0){
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