#include<bits/stdc++.h>

using namespace std;
int n,t,i,j,k;
bool m[3][3];
bool m_[3][3];
bool b;
string s;
int sum;
int counter;
int up(){
    if (j>0){
        return m[j-1][k];
    }else{
        return 0;
    }
}
int down(){
    if (j<2){
        return m[j+1][k];
    }else{
        return 0;
    }
}
int left(){
    if (k>0){
        return m[j][k-1];
    }else{
        return 0;
    }
}
int right(){
    if (k<2){
        return m[j][k+1];
    }else{
        return 0;
    }
}
void f(){
    sum = 0;
    counter++;
    if(counter==0){
        for (j=0; j<3;j++){
            for (k=0; k<3;k++){
                sum+=m[j][k];
            }    
        }
    }else{
        for (j=0; j<3;j++){
            for (k=0; k<3;k++){
                m_[j][k] = (up()+left()+right()+down())%2;//changing in copy
                // cout<<"j,k:"<<j<<k<<", ele:"<<m_[j][k]<<", ulrd:"<<up()<<left()<<right()<<down()<<endl;
                // sum+=m[j][k];
                sum+=m_[j][k];
                
            }
        }
    }
    if(sum==0){
        counter--;
    }else{
        if(counter!=0){
            for (j=0; j<3;j++){
                for (k=0; k<3;k++){
                    m[j][k] = m_[j][k];

                }
            }
        }
        f();
    }
    // for(j=0;j<3;j++){
    //     for(k=0;k<3;k++){
    //         cout<<m[j][k];
    //     }
    //     cout<<endl;
    // }
}

int main()
{   
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        // cout<<"*****************"<<endl;
        
        for(j=0;j<3;j++){
            cin>>s;
            for(k=0;k<3;k++){
                // cin>>b; //------!!!!
                // cin.clear();//------!!!!
                if(s[k]=='0'){
                    m[j][k] = 0;
                }else{
                    m[j][k] = 1;
                }

                // m[j][k] = s[k]; //------!!!!
                // cout<<s[k];
            }
            // cout<<endl;
        }
        counter=-1;
        f();
        // cout<<"counter:"<<counter<<endl;
        cout<<counter<<endl;
    }
    return 0;
}