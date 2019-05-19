// C++ program to demonstrate sorting in vector 
// of tuple according to 2nd element of tuples 
#include <bits/stdc++.h> 
using namespace std; 

// Comparison function to sort the vector elements 
// by second element of tuples 
bool sortbysec(const tuple<int, int, int>& a, 
			const tuple<int, int, int>& b) 
{ 
	return (get<1>(a) < get<1>(b)); 
} 

int main() 
{ 
	vector<tuple<int, int, int> > v; 
	v.push_back(make_tuple(10, 20, 30)); 
	v.push_back(make_tuple(15, 5, 25)); 
	v.push_back(make_tuple(3, 2, 1)); 

	// Using sort() function to sort by 2nd element 
	// of tuple 
	sort(v.begin(), v.end(), sortbysec); 
	cout << "Sorted Vector of Tuple on basis"
		" of Second element of tuple:\n"; 

	for (int i = 0; i < v.size(); i++) 
		cout << get<0>(v[i]) << " "
			<< get<1>(v[i]) << " "
			<< get<2>(v[i]) << "\n"; 
	return 0; 
} 
