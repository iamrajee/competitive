#include<bits/stdc++.h>

using namespace std;
int c;
int n,t,m;
int id;
string dir;
queue <int> l;
queue <int> r;
queue <int> f;
queue <pair<int,bool> > q;
bool b;
int i,j,k;
bool state;
int Time;
int filled;
int filled_res;
int ele,elel,eler;
pair <int,bool> p;
void funA(){
    cout<<"**************"<<i<<"***********"<<n<<" "<<t<<" "<<m<<endl;
    while(q.empty()==0){
        p = q.front();
        ele = p.first;
        b = p.second;
        cout<<ele<<","<<b<<endl;

        if(ele>Time && state==b){ //filled or not, just go!!!
            cout<<"just go20-------ele,Time = "<<ele<<","<<Time<<endl;
            // Time+=10;
            Time = max(Time+10,ele)+10;
            
            // state=!state;
            // Time+=10;
            filled = 0;
            filled++;
            filled_res =0;
        }else if(ele>Time && state!=b){
            cout<<"just go10-------ele,Time = "<<ele<<","<<Time<<endl;
            // Time+=20;
            Time = max(Time+10,ele);
            // Time=ele+20;
            state=!state;
            // Time+=10;
            filled = filled_res;
            filled++;
            filled_res =0;
        }

        if(state==b){       //print of time curr ele
            cout<<"predict10-------ele,Time = "<<ele<<","<<Time<<endl;
            cout<<"=>"<<ele<<","<<Time+10<<endl;
            filled++;
        }else{
            cout<<"predict20-------ele,Time = "<<ele<<","<<Time<<endl;
            cout<<"=>"<<ele<<","<<Time+20<<endl;
            filled_res++;
        }
        
       

        if((state==b && filled==n)){ //crossing if fulled or other called
            cout<<"filled-------ele,Time = "<<ele<<","<<Time<<endl;
            Time+=10;
            state = !state;
            filled = filled_res;
            filled_res =0;
        }else if(state!=b && filled_res==n){
            cout<<"filled-------ele,Time = "<<ele<<","<<Time<<endl;
            Time+=20;
            // state = !state;
            filled = 0;
            // filled++;                                                            
            filled_res =0;
        }
        q.pop();

        // if(b){
        //     eler=r.front();
        //     cout<<"-----"<<eler<<endl;
        //     r.pop();
        // }else{
        //     elel=l.front();
        //     cout<<"-----"<<elel<<endl;
        //     l.pop();
        // }
        // q.pop();

        // while(state ==-1 && l.empty()==0){
        //     elel = l.front();
        //     cout<<elel<<endl;
        //     // ele = elel;
        //     // l.pop();
        //     // state =-state; 
        // }


        // if(state ==-1 && ele==l.front()){
        //     elel = l.front();
        //     cout<<elel<<endl;
        //     // ele = elel;
        //     // l.pop();
        //     // state =-state; 
        // }else if(state ==1 && ele==r.front()){
        //     eler = r.front();
        //     cout<<eler<<endl;
        //     // ele = eler;
        //     // r.pop();
        //     // state =-state;
        // }


        // q.pop();


        // else{
        //     state =-state;
        // }
        // cout<<ele<<endl;

        // if(state*ele<0){//otherside
        //     Time+=10;
        //     state = -state;
        //     filled = 0;
        // }
        
        // while(state*ele<=Time && filled < n){  //load all waiting
        //     cout<<"=>"<<ele<<","<<Time+10<<endl;
        //     filled++;
        //     q.pop();
        //     ele = q.front();
        // }
        // // Time+=10;

        // if(filled==n){
        //     Time+=10;
        //     state = -state;
        //     filled = 0;
        // }
    }
}

int main()
{   
    cin >>c;
    // cout<<c<<endl;
    for(i = 0;i<c;i++){
        state=0;
        Time = 0;
        filled = 0;
        filled_res = 0;
        cin >>n>>t>>m;
        // cout<<n<<" "<<t<<" "<<m<<endl;
        for(j = 0;j<m;j++){
            cin >>id>>dir;
            // cout<<id<<" "<<dir<<endl;
            if (dir =="right"){
                q.push({id,true});
                r.push(id);
            }else{
                q.push({id,false});
                l.push(id);
            }
        }
        // while(l.empty()==0){
        //     cout<<l.front()<<endl;
        //     l.pop();
        // }
        funA();
    }
    return 0;
}