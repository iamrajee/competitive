#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h>
#include <iostream>
#include <string>
using namespace std;
clock_t tStart = clock(); //starting clock

void inputArray(int *x, int n);
int getFrequency(int *x, int n, int k);
int getMaxposn(int *x, int n);
int main()
{
	int a[100], f[100], i, n;
	cout << "Enter the no. of intergers in array(n)" << endl;
	cin >> n;

	cout << "Enter array" << endl;
	for(i=0;i<n;i++){
		cin >> a[n];
		// cout << a[n];
	}

	inputArray(a,n);

	// for(i=0; i<n; i++)
	// { 
	// 	f[i] = getFrequency(int *x, int n, int k);
	// }

	// p = getMaxposn(int *x, int n);
	// printf("%d\n", &a[p]);

	cout <<"CPU_time="<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
	return 0;
}

void inputArray(int *x, int n){
	cout << n<<endl;
	cout << x<<endl;
}




