/*
ofstream - write
ofstream (ios::app) - append
ifstream - read
fstream - both
*/

#include<iostream>
using namespace std;
#include <fstream>

int main(){
    //===================================write============
    string s = "nvoffvin isf sdfnsd";
    ofstream f1("output.txt");//-----------------open file for clear and write(ofstream)
    if (!f1){
        cout<<"error opening"<<endl;
        return -1;
    }else{
        f1<<s<<endl;
    }
    f1.close();

//===================================append============
    string s2 = "123456";
    ofstream f2("output.txt",ios::app);//-----------------open file for append(ios::app)
    if (!f2){
        cout<<"error opening"<<endl;
        return -1;
    }else{
        f2<<s2<<endl;
    }
    f2.close();
//===================================read line============
    ifstream f3("output.txt");//-----------------open file for append(ios::app)
    if (!f3){
        cout<<"error opening"<<endl;
        return -1;
    }else{
        char letter;
        for(int i=0;!f3.eof(); i++){
            f3.get(letter);
            cout<<letter;
        }
    }
    f3.close();
//===================================read char============
    ifstream f4("output.txt");//-----------------open file for append(ios::app)
    if (!f4){
        cout<<"error opening"<<endl;
        return -1;
    }else{
        string s;
        for(int i=0;!f4.eof(); i++){
            getline(f4,s);
            cout<<s<<endl;
        }
    }
    f4.close();
    return 0;
}