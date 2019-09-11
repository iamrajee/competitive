//segment max tree
#include <bits/stdc++.h> 
using namespace std; 

int getMid(int s, int e) { return s + (e - s) / 2; } 
int MaxUtil(int* st, int ss, int se, int l, int r, int node) { 
	if (l <= ss && r >= se) //segment part of given range
		return st[node]; 
	if (se < l || ss > r) //not at all
		return -1; 
	int mid = getMid(ss, se); //partially
	return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, se, l, r, 2 * node + 2)); 
} 

void updateValue(int arr[], int* st, int ss, int se, int index, int value, int node) { 
	if (index < ss || index > se) { 
		cout << "Invalid Input" << endl; 
		return; 
	} 
	if (ss == se) { 
		arr[index] = value; 
		st[node] = value; 
	} 
	else { 
			int mid = getMid(ss, se); 
			if (index >= ss && index <= mid) 
				updateValue(arr, st, ss, mid, index, value, 2 * node + 1); 
			else
				updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2); 
			st[node] = max(st[2 * node + 1], st[2 * node + 2]); 
	} 
	return; 
} 

int getMax(int* st, int n, int l, int r) 
{ 
	if (l < 0 || r > n - 1 || l > r) { 
		printf("Invalid Input"); 
		return -1; 
	} 
	return MaxUtil(st, 0, n - 1, l, r, 0); 
} 

int constructSTUtil(int arr[], int ss, int se, int* st, int si){ 
	if (ss == se){ //if one ele 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 
	int mid = getMid(ss, se); 
	st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1), constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)); 
	return st[si]; 
} 

int* constructST(int arr[], int n) { 
	int x = (int)(ceil(log2(n))); 
	int max_size = 2 * (int)pow(2, x) - 1; 
	int* st = new int[max_size]; 
	constructSTUtil(arr, 0, n - 1, st, 0); 
	return st; 
} 

int main() { 
	int arr[] = { 1, 3, 5, 7, 9, 11 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int* st = constructST(arr, n); 
	cout << "Max of values in given range = "<< getMax(st, n, 1, 3) << endl; 
	updateValue(arr, st, 0, n - 1, 1, 8, 0); 
	cout << "Updated max of values in given range = "<< getMax(st, n, 1, 3) << endl; 
	return 0; 
}