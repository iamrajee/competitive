#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
clock_t tStart = clock(); //starting clock

vector <int> inputArray(int n);
void getFrequency(int *,vector <int>, int);
int getMaxposn(int *x, int n);
int main()
{
	int f[100], n;
	vector <int> a;
	a = inputArray(n);

	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
	}
	getFrequency(f,a,n);
	

	// p = getMaxposn(int *x, int n);
	// printf("%d\n", &a[p]);

	cout <<"CPU_time="<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
	return 0;
}

vector <int> inputArray(int n){
	vector <int> a;
	int x;

	cout << "Enter the no. of intergers in array(n)" << endl;
	cin >> n;

	cout << "Enter array" << endl;
	for(int i=0;i<n;i++){
		cin >> x;
		a.push_back(x);
	}
	return a;
}

void getFrequency(int *f,vector <int> a, int n){
	for(int i=0; i<n; i++){
		cout << "--"<<a[i]<<endl;
		// for(int j=0; j<n; i++){ 
			
		// }
	}
}



