#include <bits/stdc++.h> 
using namespace std; 
int merge(int arr[], int temp[], int l, int m, int r) { 
	int i, j, k; 
	int ctr = 0; 
	i = l;
	j = m;
	k = l;
	while ((i <= m - 1) && (j <= r)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else{ 
			temp[k++] = arr[j++]; 
			ctr+=(m - i); 
		} 
	} 
	while (i <= m - 1) 
		temp[k++] = arr[i++]; 
	while (j <= r) 
		temp[k++] = arr[j++]; 
	for (i = l; i <= r; i++) 
		arr[i] = temp[i]; 
	return ctr; 
} 
int mergeSort(int arr[], int temp[], int l, int r) { 
	int m, ctr = 0; 
	if (l<r) { 
		m = (r + l) / 2; 
		ctr = mergeSort(arr, temp, l, m); 
		ctr += mergeSort(arr, temp, m + 1, r); 
		ctr += merge(arr, temp, l, m + 1, r); 
	} 
	return ctr; 
}
int main() { 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
	int ans = mergeSort(arr, temp, 0, n-1); 
	cout << " Number of inversions are " << ans<<endl; 
	return 0;
}