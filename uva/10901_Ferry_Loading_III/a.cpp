#include<bits/stdc++.h>

using namespace std;
int c;
int n,t,m;
int id;
string dir;
queue <int> q;
int i,j,k;
int state;
int Time;
int filled;
int filled_res;
int ele;

void funA(){
    cout<<"**************"<<i<<"***********"<<n<<" "<<t<<" "<<m<<endl;
    for(int k; k<m;k++){
        if(filled_res!=0){
            filled=filled_res;
        }
        ele = q.front();
        cout<<ele<<endl;
        // q.pop();

        if(state*ele<0){//otherside
            cout<<"=>"<<-ele<<","<<Time+20<<endl;
            filled_res++;
            q.pop();
            ele = q.front();
            
            while(abs(state*ele)==Time && filled_res <= n && filled <= n){  //load all waiting
                if(state*ele<0 && filled_res < n){
                    cout<<"===>"<<-ele<<","<<Time+20<<endl;
                    filled_res++;
                }else if(state*ele>0 && filled < n){
                    cout<<"==>"<<ele<<","<<Time+10<<endl;
                    filled++;
                }
                q.pop();
                ele = q.front();
            }


            Time+=10;
            state = -state;
            filled = 0;
        }
        
        while(state*ele<=Time && filled < n){  //load all waiting
            cout<<"=>"<<ele<<","<<Time+10<<endl;
            filled++;
            q.pop();
            ele = q.front();
        }
        // Time+=10;

        if(filled==n){
            Time+=10;
            state = -state;
            filled = 0;
        }
    }
}

int main()
{   
    cin >>c;
    // cout<<c<<endl;
    for(i = 0;i<c;i++){
        state=-1;
        Time = 0;
        filled = 0;
        filled_res = 0;
        cin >>n>>t>>m;
        // cout<<n<<" "<<t<<" "<<m<<endl;
        for(j = 0;j<m;j++){
            cin >>id>>dir;
            // cout<<id<<" "<<dir<<endl;
            if (dir =="right"){
                id = -id;
            }
            q.push(id);
        }
        funA();
    }
    return 0;
}