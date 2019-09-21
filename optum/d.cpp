#include <bits/stdc++.h> 
using namespace std; 

int getOccurence(int n, int d) { 
	int result = 0; // Initialize result 
	int itr = d; 
	while (itr <= n) 
	{ 
		
		if ((itr != 0) && ((itr/10) == d)){ // When the first digit is equal to d then 
			result++; // increment result as well as number
			itr++; //40->41->42...
            cout<<itr<<","<<itr/10<<","<<d<<endl;
		}else if(itr%10 == d){ // When the last digit is equal to d 
			result++;
            cout<<"-"<<itr<<endl;
            if((int)(itr/10) == (d-1)){ // In case of reverse of number such as 12 and 21
			    itr = itr + (10 - d);//34->40
            }else{
			    itr = itr+10;//24->34
            }
        }else{
            itr++;
        }
	}
	return result; 
} 
int main(void) { 
	int n = 30, d = 1; 
	cout << getOccurence(n, d)<<endl; 
	return 0; 
} 