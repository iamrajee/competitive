#include<bits/stdc++.h>

using namespace std;
int sz,p,t,i,j,k;
int x;
int r,c;
int centre;
// int p_,t_;
int counter;

void f(){
    centre = (sz+1)/2;
    t=1;
    counter=0;
    while(p>=0){
        // p_ = p;
        // t_ = t;
        p=p-t;
        counter++;
        if(counter==2){
            t++;
             counter=0;
        }
    }
    if(counter==0){
        if(p==0){
            x=0;
        }else{
            t--;
            x = p+t;
        }
        counter=1;
    }else{//1
        if(p==0){
            x=0;
        }else{
            x = p+t;
            t--;
        }
        counter=2;
    }
    cout<<"t:"<<t<<", counter:"<<counter<<", x:"<<x<<endl;
    if(t%2){//odd
        if(counter==1){
            cout<<"up:"<<x<<endl;
            r = centre + (t-1)/2;
            c = centre + (t-1)/2-x;
            // if(x!=0){
            //     r = centre + (t+1)/2;
            //     c = centre + (t+1)/2-x;
            // }else{
            //     r = centre + (t+1)/2-1;
            //     c = centre + (t+1)/2-1;
            // }
        }else{
            cout<<"left:"<<x<<endl;
            r = centre + (t-1)/2-x;
            c = centre - (t-1)/2;
        }
    }else{//even
        if(counter==1){
            cout<<"down:"<<x<<endl;
            r = centre - (t+1)/2;
            c = centre - (t+1)/2+x;
        }else{
            cout<<"right:"<<x<<endl;
            r = centre - (t+1)/2+x;
            c = centre + (t+1)/2;
        }
    }
    cout<<"r:"<<r<<", c:"<<c<<endl;
}

int main()
{   
    cin>>sz>>p;
    while(sz!=0 && p!=0){
        cout<<"*********"<<sz<<" "<<p<<"*********"<<endl;
        f();
        cin>>sz>>p;
    }
    return 0;
}