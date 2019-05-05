#include <iostream> //cin,cout
using namespace std;

// #include<stdio.h>
// #include <stdlib.h>
// #include<time.h>
// #include<unistd.h>
// #include <string>
// #include <vector>

clock_t tStart = clock(); //starting clock

class first{
	int a,b,c;
	public:
	void read(){
		cout<<"enter 3 no."<<endl;
		cin>>a>>b>>c;
	}
	void write(){
		cout<<a<<b<<c<<endl;
	}
};

int main()
{	first f;
	f.read();
	f.write();
	cout <<"CPU_time="<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
	return 0;
}




