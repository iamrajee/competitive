#include<bits/stdc++.h>

using namespace std;
int n,k,t,i,j,l,v,m;
char c;
string s;
map <char, int> cmap;
pair <char, int> p;
float sum;
int main()
{   
    cin >>n;
    // cout<<n<<endl;
    for(i = 0;i<n;i++){
        sum = 0;
        cin >>k;
        // cout<<k<<endl;
        for(j = 0;j<k;j++){
            cin>>c>>v;
            // p = {c,v};
            // cmap.insert(p);
            cmap[c] = v;
            // cout<<c<<v<<endl;
        }

        // map<char, int>::iterator itr; 
        // for (itr = cmap.begin(); itr != cmap.end(); ++itr) { 
        //     cout << '\t' << itr->first 
        //      << '\t' << itr->second << '\n';
        // }
        // cout << endl;

        cin >>m;
        // cout<<m<<endl;
        getline(cin,s); //ignore
        for(j = 0;j<m;j++){
            getline(cin,s);
            // cout<<s<<endl;
            for(l=0; l<s.size(); l++){
                // cout<<s[l];
                if(cmap[s[l]]!=0){
                    sum+=cmap[s[l]];
                }
            }
            // cout<<endl;
        }
        printf("%.2f$\n",sum/100);
    }
    return 0;
}