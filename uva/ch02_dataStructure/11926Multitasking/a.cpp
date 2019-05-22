#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,J1,J2,k,t1,t1_,t2,t2_,r,r_;
vector <pair<int,int>> one;
vector <tuple<int,int,int>> rep;
int flag;
int counter=0;
int main()
{   cin>>n>>m;
    while(n||m){
        flag = 0;
        one.clear();
        rep.clear();
        // cout<<++counter<<"****"<<n<<" "<<m<<"****"<<endl;
        for(i=0; i<n; i++){
            cin>>t1>>t2;

            if(flag){
                continue;
            }

            for(auto it:one){
                t1_ = it.first;
                t2_ = it.second;
                if( (t1_<t1&&t1<t2_) || (t1_<t2&&t2<t2_) ){
                    // cout<<"=>"<<t1_<<" "<<t2_<<endl;
                    flag=1;
                    break;
                }else if((t1<t1_&&t1_<t2) || (t1<t2_&&t2_<t2)){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                continue;
            }
            // cout<<t1<<" "<<t2<<endl;
            one.push_back({t1,t2});
        }
        // if(flag){
        //     cin>>n>>m;
        //     continue;
        // }
        for(i=0; i<m; i++){
            cin>>t1>>t2>>r;

            if(flag){
                continue;
            }

            for(auto it:one){//multi checked with one
                t1_ = it.first;
                t2_ = it.second;
                if(t2_<t1){
                    continue;
                }
                J1 = ((float)(t1_ - t1)/r<0)?0:(t1_ - t1)/r+1;
                J2 = ((float)(t1_ - t2)/r<0)?0:(t1_ - t1)/r+1;
                // cout<<"==>"<<t1_<<" "<<t1+J1*r<<" "<<t2+J2*r<<" "<<t2_<<endl;
                if( (t1_<t1+J1*r&&t1+J1*r<t2_) || (t1_<t2+J2*r&&t2+J2*r<t2_) ){
                    // cout<<"==>"<<t1_<<" "<<t1+J1*r<<" "<<t2+J2*r<<" "<<t2_<<endl;
                    // cout<<"==>"<<t1_<<" "<<t2_<<endl;
                    flag=1;
                    break;
                }else if(J1>0){
                    J1--;
                    if(t1+J1*r<t1_ && t1_<t2+J1*r){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                continue;
            }

            for(auto it:rep){//multi checked with multi
                t1_ = get<0>(it);
                t2_ = get<1>(it);
                r_ = get<1>(it);
                // cout<<"===>"<<t1_<<" "<<t2_<<" "<<r_<<endl;
                while(t2_<1000000){
                    if(t1>t2_){
                        t1_ +=r_;
                        t2_ +=r_;
                        continue;
                    }
                    J1 = ((float)(t1_ - t1)/r<0)?0:(t1_ - t1)/r+1;
                    J2 = ((float)(t1_ - t2)/r<0)?0:(t1_ - t1)/r+1;
                    
                    // cout<<"=>"<<t1_<<" "<<t2_<<endl;
                    // cout<<"====>"<<t1_<<" "<<J1<<" "<<J2<<" "<<t2_<<endl;
                    if( (t1_<t1+J1*r&&t1+J1*r<t2_) || (t1_<t2+J2*r&&t2+J2*r<t2_) ){
                        flag=1;
                        break;
                    }else if(J1>0){
                        J1--;
                        if(t1+J1*r<t1_ && t1_<t2+J1*r){
                            flag=1;
                            break;
                        }
                    }
                    t1_ +=r_;
                    t2_ +=r_;
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                continue;
            }

            // cout<<t1<<" "<<t2<<" "<<r<<endl;
            rep.push_back(make_tuple(t1,t2,r));
        }

        if(!flag){
            cout<<"NO CONFLICT"<<endl;
        }

        
        cin>>n>>m;
    }
    return 0;
}