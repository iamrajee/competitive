#include <iostream> 
#include <set> 
#include <iterator> 

using namespace std; 

int main() 
{ 
	set <int, greater <int> > s;		 

	s.insert(40); 
	s.insert(30); 
	s.insert(60); 
	s.insert(20); 
	s.insert(50); 
	s.insert(50); // only one 50 will be added to the set 
	s.insert(10);

	// printing set s 
	set <int, greater <int> > :: iterator itr; 
	cout << "\nThe set s is : "; 
	for (itr = s.begin(); itr != s.end(); ++itr) 
	{ 
		cout << '\t' << *itr; 
	} 
	cout << endl; 

	// assigning the elements from s to gquiz2 
	set <int> gquiz2(s.begin(), s.end()); 

	// print all elements of the set gquiz2 
	cout << "\nThe set gquiz2 after assign from s is : "; 
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
	{ 
		cout << '\t' << *itr; 
	} 
	cout << endl; 

	// remove all elements up to 30 in gquiz2 
	cout << "\ngquiz2 after removal of elements less than 30 : "; 
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30)); 
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
	{ 
		cout << '\t' << *itr; 
	} 

	// remove element with value 50 in gquiz2 
	int num; 
	num = gquiz2.erase (50); 
	cout << "\ngquiz2.erase(50) : "; 
	cout << num << " removed \t" ; 
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
	{ 
		cout << '\t' << *itr; 
	} 

	cout << endl; 

	//lower bound and upper bound for set s 
	cout << "s.lower_bound(40) : "
		<< *s.lower_bound(40) << endl; 
	cout << "s.upper_bound(40) : "
		<< *s.upper_bound(40) << endl; 

	//lower bound and upper bound for set gquiz2 
	cout << "gquiz2.lower_bound(40) : "
		<< *gquiz2.lower_bound(40) << endl; 
	cout << "gquiz2.upper_bound(40) : "
		<< *gquiz2.upper_bound(40) << endl; 

	return 0; 

} 
