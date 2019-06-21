#include<bits/stdc++.h>
using namespace std;

int i,k,t;
int a,b,l,r;
long long int as,bs,ps,lcms;
int cl,fl,dl,lcm;

class gfg 
{ 
    public : int gcd(int a_, int b_){ 
       if (a_ == 0) 
           return b_;  
       return gcd(b_ % a_, a_);  
    } 
    int LCM(int a_, int b_)  
    {  
       return (a_*b_)/gcd(a_, b_);  
    }  
};

int main(){
    cin>>t;
    gfg g; 
    // cout<<n<<endl;
    as=0;
    bs=0;
    ps=0;
    lcms=0;

    k=0;
    for(i=0;i<t;i++){
        cin>>a>>b>>l>>r;
        if(l>r){
            cout<<"TRUE LOVE"<<endl;
            continue;
        }
        cl=ceil((float)l/a);
        k=cl*a;
        if(k<=r){
            fl = floor((float)r/a);
            // cout<<cl*a<<" "<<fl*a<<endl;
            dl= fl-cl;
            // as = k*(dl+1) + a*(dl*(dl+1))/2;
            if(dl>-1){
                as = k*(dl+1) + a*(dl*(dl+1))/2;
            }else{
                as=0;
            }
        }
        cl=ceil((float)l/b);
        k=cl*b;
        if(k<=r){
            fl = floor((float)r/b);
            // cout<<cl*b<<" "<<fl*b<<endl;
            dl= fl-cl;
            if(dl>-1){
                bs = k*(dl+1) + b*(dl*(dl+1))/2;
            }else{
                bs=0;
            }
        }

        lcm=g.LCM(a, b);
        cl=ceil((float)l/lcm);
        k=cl*lcm;
        if(k<=r){
            fl = floor((float)r/lcm);
            // cout<<cl*lcm<<" "<<fl*lcm<<endl;
            dl= fl-cl;
            // lcms = k*(dl+1) + lcm*(dl*(dl+1))/2;
            if(dl>-1){
                lcms = k*(dl+1) + lcm*(dl*(dl+1))/2;
            }else{
                lcms=0;
            }
        }
        cout<<as<<" "<<bs<<" "<<lcms<<endl;

        ps=as+bs;
        if(abs(ps-lcms)%2 == 0){
            if(ps%2 == 0 || ps%3 == 0){
                cout<<"TRUE LOVE"<<endl;
            }else
            {
                cout<<"LOVE"<<endl;
            }
        }else
        {
            if(ps%2 == 0 || ps%3 == 0){
                cout<<"LOVE"<<endl;
            }else
            {
                cout<<"FAKE LOVE"<<endl;
            }
        }
        

    }
    return 0;
}