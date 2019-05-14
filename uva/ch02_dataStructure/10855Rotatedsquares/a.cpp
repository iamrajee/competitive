#include<bits/stdc++.h>

using namespace std;
int N,n,t,i,j,k;
string s;
char c;
vector <vector <char> > m;
vector <vector <char> > M;
int result[4];
int counter;
int flag;

void printm() { 
    cout<<"--------- m --------------"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%c ", m[i][j]); 
        cout<<endl; 
    }
    cout<<endl;
}

void rotM() { //90 degree anti-clockwise
    for (int x = 0; x < n / 2; x++) { 
        for (int y = x; y < n-x-1; y++) { 
            char temp = m[x][y]; 
            m[x][y] = m[y][n-1-x]; // move values from right to top 
            m[y][n-1-x] = m[n-1-x][n-1-y]; // move values from bottom to right 
            m[n-1-x][n-1-y] = m[n-1-y][x]; // move values from left to bottom 
            m[n-1-y][x] = temp;  // assign temp to left 
        }
    } 
}
void match(){
    counter=0;
    for(i=0;i<N-n+1;i++){
        for(j=0;j<N-n+1;j++){
            if(M[i][j]==m[0][0]){
                flag=0;
                for(int im=0;im<n;im++){
                    for(int jm=0;jm<n;jm++){
                        if(M[i+im][j+jm]!=m[im][jm]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) counter++;
            }
    }
    }
}
void f(){
    // printm();
    match(); //0
    result[0]=counter;

    rotM();  //270
    // printm();
    match();
    result[3]=counter;

    rotM();    //180
    match();
    // printm();
    result[2]=counter;

    rotM();     //90
    match();
    // printm();
    result[1]=counter;

    // cout <<"result : ";
    for(int k=0;k<4;k++){
        if(k) cout<<" ";
        cout<<result[k];
    }
    cout<<endl;
}

int main()
{   
    cin>>N>>n;
    while(N!=0 && n!=0){
        m.clear();
        M.clear();
        // cout<<"*********"<<N<<" "<<n<<"*********"<<endl;
        for(i=0;i<N;i++){
            cin>>s;
            // cout<<s<<endl;
            M.push_back(vector <char> ());
            for(j=0;j<N;j++){
                M[i].push_back(s[j]);
            }
        }
        for(i=0;i<n;i++){
            cin>>s;
            // cout<<s<<endl;
            m.push_back(vector <char> ());
            for(j=0;j<n;j++){
                m[i].push_back(s[j]);
            }
        }
        f();
        cin>>N>>n;
    }
    return 0;
}