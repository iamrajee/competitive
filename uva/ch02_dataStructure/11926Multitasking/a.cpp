#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,J1,J2,k,t1,t1_,t2,t2_,r,r_;
vector <pair<int,int>> one;
vector <tuple<int,int,int>> rep;
int flag;
int main()
{   cin>>n>>m;
    while(n||m){
        flag = 0;
        one.clear();
        rep.clear();
        cout<<"****"<<n<<" "<<m<<"****"<<endl;
        for(i=0; i<n; i++){
            cin>>t1>>t2;

            for(auto it:one){
                t1_ = it.first;
                t2_ = it.second;
                cout<<"=>"<<t1_<<" "<<t2_<<endl;
                if( (t1_<t1&&t1<t2_) || (t1_<t2&&t2<t2_) ){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                break;
            }
            cout<<t1<<" "<<t2<<endl;
            one.push_back({t1,t2});
        }
        if(flag){
            cin>>n>>m;
            continue;
        }
        for(i=0; i<m; i++){
            cin>>t1>>t2>>r;

            for(auto it:one){//multi checked with one
                t1_ = it.first;
                t2_ = it.second;
                J1 = (t1_ - t1)/r+1;
                J2 = (t1_ - t2)/r+1;
                cout<<"=>"<<t1_<<" "<<t2_<<endl;
                if( (t1_<t1+J1*r&&t1+J1*r<t2_) || (t1_<t2+J2*r&&t2+J2*r<t2_) ){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                break;
            }

            for(auto it:rep){//multi checked with multi
                t1_ = get<0>(it);
                t2_ = get<1>(it);
                r_ = get<1>(it);

                if(t1<t1_){
                    J1 = (t1_ - t1)/r;
                    // t1+J1*r
                }else if(t1>t1_){
                    J2 = (t1 - t1_)/r_;
                    // t_+J2*r_
                }else{
                    flag=1;
                    break;
                }

                J1 = (t1_ - t1)/r+1;
                J2 = (t1_ - t2)/r+1;
                cout<<"=>"<<t1_<<" "<<t2_<<endl;
                if( (t1_<t1+J1*r&&t1+J1*r<t2_) || (t1_<t2+J2*r&&t2+J2*r<t2_) ){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"CONFLICT"<<endl;
                break;
            }

            cout<<t1<<" "<<t2<<" "<<r<<endl;
            rep.push_back(make_tuple(t1,t2,r));
        }

        if(!flag){
            cout<<"NO CONFLICT"<<endl;
        }

        
        cin>>n>>m;
    }
    return 0;
}