#include<bits/stdc++.h>

// #include <iostream> 
// #include <queue>
// #include <fstream>
// 
// #include<stdio.h>
// #include<fstream>
// 
// #include <stdlib.h>
// #include<stack>
// #include<stackint>

using namespace std; 
  
int main() 
{ 
    int r,n,s,q,t,xn;
    cin >>r;
    cout<<r<<endl;
    
    for(int i = 0;i<r;i++){
        stack <int> carrier;
        cin >>n>>s>>q;
        cout<<n<<" "<<s<<" "<<q<<" "<<endl;
        // queue <int> * qlist = (queue <int> *)malloc(n*sizeof(queue <int>));  //insead of list of queue take vector of queue
        vector < queue <int> > qv;
        qv.clear();
        for(int j = 0;j<n;j++){
            qv.push_back(queue<int>());
            cin>>xn;
            cout<<xn<<" ";
            for(int k = 0;k<xn;k++){
                cin>>t;
                cout<<t<<" ";
                qv[j].push(t);
            }
            cout<<endl;
        }
        int state=0;
        int last_loaded_from=-1;
        int last_non_empty=-1;
        int counter=0;
        int totaltime=0;
        int flag=0;
        while(state+1!=last_loaded_from && counter <30){
            // counter++;
            totaltime+=2;
            if(last_non_empty==state+1){
                flag=1;
            }

            cout<<"---------- State : "<<state+1<<",      last_loaded_from:"<<last_loaded_from<<endl;
            if(!carrier.empty()){
                cout<<"=>carrier top : " << carrier.top()<<endl;
            }
            // for (int w=0;w<carrier.size())
            // if(!qv[state].empty()){
                //un-loading to A or B
                while(!carrier.empty()){
                    totaltime++;
                    if (carrier.top()==state+1){
                        carrier.pop();//dump to A
                        cout<<"A:"<<state+1<<endl;
                    }else if(qv[state].size()<q){
                        qv[state].push(carrier.top());//unload to B
                        cout<<"B:"<<carrier.top()<<endl;
                        carrier.pop();
                    }else{
                        break;
                    }
                }
                //re-loading carrier
                while(!qv[state].empty() && carrier.size()<s){
                    totaltime++;
                    last_loaded_from = state+1;
                    int c = qv[state].front();
                    qv[state].pop(); //remove B
                    carrier.push(c); //load on carrier
                    cout<<"loaded: "<<c<<endl;
                }
            // }
            if (state == n-1){
                state=0;
            }else{
                state++;
            }

            if(!qv[state].empty()){
                last_non_empty = state+1;
            }
            if(carrier.empty() && flag==1){
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>> Empty!!!"<<endl;
                break;
            }
        }
        cout<<"************************totaltime:"<<totaltime<<endl;
    }

    return 0;
}