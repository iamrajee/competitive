#include<bits/stdc++.h>

using namespace std;
int sz,t,i,j,k;
int x;
int r,c;
int cx,cy;
long int sum,p;
// int sum_;
int delta;
// int p_,t_;
int counter;
void up(){
    cx+=t;
}
void left(){
    cy-=t;
}
void down(){
    cx-=t;
}
void right(){
    cy+=t;
}
void f(){
    cx = (sz+1)/2;
    cy = (sz+1)/2;
    t=1;
    counter=0;
    sum=1;
    // sum_ = sum;
    while(sum+t<=p){
        // p=p-t;
        // sum_ = sum;
        sum+=t;
        counter++;
        if(counter==1){
            up();
        }else if(counter==2){
            left();
        }else if(counter==3){
            down();
        }else if(counter==4){
            right();
        }

        if(counter%2==0){//2,4
            t++;
            if(counter==4)  counter=0;
        }
                
        
    }
    delta = p-sum;
    if(delta){
       if(counter==1){
            cy-=delta;
        }else if(counter==2){
            cx-=delta;
        }else if(counter==3){
            cy+=delta;
        }else if(counter==0){//4
            cx+=delta;
        }
    }
    // cout<<"cx:"<<cx<<", cy:"<<cy<<", counter:"<<counter<<", delta:"<<delta<<endl;
    cout<<"Line = "<<cx<<", column = "<<cy<<"."<<endl;
}

int main()
{   
    cin>>sz>>p;
    while(sz!=0 && p!=0){
        // cout<<"*********"<<sz<<" "<<p<<"*********"<<endl;
        f();
        cin>>sz>>p;
    }
    return 0;
}