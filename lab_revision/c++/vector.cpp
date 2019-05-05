#include<iostream>
using namespace std;

#include<vector>

int main(){
    vector <int> v;
    for(int i=0;i<5;i++){
        v.push_back(i); //----------------------insert
    }
    v.insert(v.begin(),-1); //------------------insert at begin
    cout<<v[4]<<endl;
    v[0] = -2;//----------------------change
    for (int i; i <v.size(); i++){//----------------------loop
        cout<<v[i]<<endl;//----------------------use
    }

    if (!v.empty()){
        cout<<"not empty"<<endl;
    }

    v.clear();
    return 0;
}