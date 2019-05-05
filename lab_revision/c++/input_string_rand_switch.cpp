#include <iostream> //cin,cout
using namespace std;//getting rid of std:: before cin and cout

#include<stdio.h>
#include<fstream>

#include <stdlib.h>
#include<unistd.h>

#include<time.h>

#include <string> //string
#include <vector> //for array of string etc

clock_t tStart = clock(); //starting clock

class first{//-----------------------------------------------------class
	string a,b,c,s1,s2;
	public:
	void read(){
		cout<<"enter statement."<<endl;
		getline(cin,s1);
		cout<<"enter a number."<<endl;
		getline(cin,s2);
		cout<<"enter 3 words."<<endl;
		cin>>a>>b>>c;
	}
	void write(){
		cout << s1 <<endl;
		int d = atoi(s2.c_str());//-------------------------------------------------atoi
		cout << "string:"<<s2 <<"  number:"<< d << endl;
		cout<<"hello "+a+b+c<<endl;
	}
};

int main()
{	first f; //-------------------------------------------------object
	// f.read();
	// f.write();

	int e;
	// cout<<"enter int : ";
	// cin >> e;

	srand (time(NULL)); //----------------------------------- random no.
	e = rand()%5+1;

	cout << e <<endl;
	switch(e){//--------------------------------------------------switch
		case 5: cout <<"Hi rajee"<<endl;
		default: cout <<"lol"<<endl;
	}

	cout <<"CPU_time="<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
	return 0;
}
