#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,count;
long long int sum;
int a,b,t;
char c;
string s;
int main(){
    // vector<int> Solution::maxset(vector<int> &A) {

    //cout<<A<<endl;
    vector <int> A;
    // A.push_back(1);
    // A.push_back(2);
    // A.push_back(5);
    // A.push_back(-7);
    // A.push_back(2);
    // A.push_back(3);
    // -846930886, -1714636915, 424238335, -1649760492
    // A.push_back(-846930886);
    // A.push_back(-1714636915);
    // A.push_back(424238335);
    // A.push_back(-1649760492);

    // 1967513926, 1540383426, -1303455736, -521595368

    // A.push_back(1967513926);
    // A.push_back(1540383426);
    // A.push_back(-1303455736);
    // A.push_back(-521595368);

    // 756898537, -1973594324, -2038664370, -184803526, 1424268980
    A.push_back(756898537);
    A.push_back(-1973594324);
    A.push_back(-2038664370);
    A.push_back(-184803526);
    A.push_back(1424268980);

    vector <int> v;
    set <tuple<long long int,int,int,int,int> > st;
    int sz=(int)A.size();
    int i,i_;
    i_=-1;
    sum=0;
    for(i=0;i<sz;i++){
        if(A[i]<0){
            // cout<<"hi"<<endl;
            cout<<sum<<" "<<i_<<" "<<i<<" "<<endl;
            st.insert(make_tuple(sum,i-i_-1,sz-i_,i_,i));
            i_=i;
            sum=0;
        }else{
            sum+=A[i];
        }
        
    }
    // i--;
    if(!(A[sz-1]<0)){
        cout<<sum<<" "<<i_<<" "<<i<<" "<<endl;
        st.insert(make_tuple(sum,i-i_-1,sz-i_,i_,i));
    }
    
    auto it = st.rbegin();
    int start = get <3> (*it);
    int end = get <4> (*it);
    // cout<<start<<" "<<end<<", sum:"<<get <0> (*it)<<endl;

    // for(auto it:st){
    //     start = get <3> (it);
    //     end = get <4> (it);
    //     cout<<"> sum:"<<get <0> (it)<<" "<<start<<" "<<end<<endl;
    // }
    for(i=start+1;i<end;i++){
        v.push_back(A[i]);
    }
    // return v;
    for(auto it:v){
        cout<<it<<" ";
    }

// }

}