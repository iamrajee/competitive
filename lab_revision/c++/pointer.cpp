#include<iostream>
using namespace std;
#include<vector>

// #include <string.h>
// #include<stdio.h>
#include<stdlib.h> //malloc

int* funA(int, int*,int*,int*); //declaration

vector <int> funB(){
    vector <int> v;
    for(int i=0;i<5;i++){
        v.push_back(i);
    }
    return v;
}

int main(){
    int a = 5;
    int b = 5;
    int *c;
    int A2[3] = {10,20,30};
    cout<<"A2:";
    for(int i=0; i<3; i++){
        cout<<A2[i]<<",";
    }
    cout<<endl;

    cout<<"-------------------------"<<endl;
    int *A = funA(a,&b, c, A2);
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;

    cout<<"A:"<<A<<"  *A:"<<*A<<endl;
    *A++;//---------------------------!!! it's not incr. by 1, it's next ele or array
    cout<<"A:"<<A<<"  *A:"<<*A<<endl;

    cout<<"A2:";
    for(int i=0; i<3; i++){
        cout<<A2[i]<<",";
    }
    cout<<endl;

cout<<"============================"<<endl;
    vector < int> v;
    // v.clear();
    v = funB();
    cout<<"v:";
    for( int i=0; i< v.size(); i++)
        cout << v[i] << " " ;
    cout<<endl;
cout<<"============================"<<endl;

    v.clear();
    return 0;
}

int* funA(int a,int*b_ptr,int*z,int*A2_ptr){
    int a1[3] = {10,20,30};
    int *a2 = (int *) malloc (3 * sizeof (int));
    // a2 = {10,20,30}; //can't do like this
    a2[0] = 10; //insead this way or in loop
    a2[1] = 20;
    a2[2] = 30;


    for(int i=0; i<3; i++){
        cout<<a1[i]<<",";
    }
    cout<<endl;
    cout<<"a:"<<a<<endl;
    cout<<"b_ptr:"<<b_ptr<<endl;
    cout<<"*b_ptr:"<<*b_ptr<<endl;
    a++;
    *b_ptr = 6;

    cout<<"A2_ptr:"<<A2_ptr<<endl;
    cout<<"*A2_ptr:"<<*A2_ptr<<endl;
    A2_ptr++;
    cout<<"A2_ptr:"<<A2_ptr<<endl;
    cout<<"*A2_ptr:"<<*A2_ptr<<endl;

    A2_ptr--;
    *A2_ptr=-10;

    cout<<"-------------------------"<<endl;


    // return a1; //local variable addr. cant be returned simply
    // return a2; //if want to then use malloc
    z = a1;//or copy the addr. into other func. parameter and return.
            //or use vector(used in fun B)
    return z;
}