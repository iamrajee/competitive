#include <bits/stdc++.h>
using namespace std;
int lps(string s){ 
    int n = s.size();
    int i, j, len;
    int dp[n][n];

    for (i = 0; i < n; i++) 
	    dp[i][i] = 1; 

    for (len=2; len<=n; len++){ 
	    for (i=0; i<n-len+1; i++){ 
	    	j = i+len-1; 
	    	if (s[i] == s[j] && len == 2) 
	    	    dp[i][j] = 2; 
	    	else if (s[i] == s[j]) 
	    	    dp[i][j] = dp[i+1][j-1] + 2; 
	    	else
	    	    dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
	    } 
	}
    cout<<dp[0][n-1]<<endl;
	return dp[0][n-1]; 
} 

int main() { 
	string s = "GEEKS FOR GEEKS"; 
	lps(s);
	return 0; 
} 
