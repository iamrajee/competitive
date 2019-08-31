#include <iostream>
#include <string>
using namespace std;
const int P_B= 227;
const int P_M = 1000005;
int Hash(const string& s) {
   int r = 0;
   for (int i = 0; i < s.size(); i++) {
      r = r* P_B + s[i];
      r %= P_M;
   }
   return r;
}
int rabin_karp(const string& n, const string& hstack) {
   int h1 = Hash(n);
   int h2 = 0;
   int power = 1;
   for (int i = 0; i < n.size(); i++)
      power = (power * P_B) % P_M;
   for (int i = 0; i < hstack.size(); i++) {
      h2 = h2*P_B + hstack[i];
      h2 %= P_M;
      if (i >= n.size()) {
         h2 -= power * hstack[i-n.size()] % P_M;
         if (h2 < 0)
            h2 += P_M;
      }
      if (i >= n.size()-1 && h1 == h2)
         return i - (n.size()-1);
   }
   return -1;
}
int main() {
   string s1, s2;
   cout<<"Enter Input String: ";
   getline(cin, s1);
   cout<<"Enter String to find: ";
   cin>>s2;
   if(rabin_karp(s2, s1) == -1)
      cout<<"String not found"<<endl;
   else
      cout<<"String"<<" "<<s2<<" "<<"found at position "<<rabin_karp(s2, s1)<<endl;
   return 0;
}