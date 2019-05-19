#include<bits/stdc++.h>
#include<tuple>

using namespace std;
int n,i,j,k;
char c;
string s;
int qsum;

// multiset <int,int> cs;
// multiset <int,int> is;
// multiset <int,int> os;
set <pair<int,int> > cs;
multiset <pair<int,int> > is;
// multiset <int,int,int> rs;
// multiset <pair<int,int> > os;
set <int> allid;
set <int> solvedq;
set <int> solvedid;
set <int>::iterator itr3;
set <int>::iterator itr4;


// multiset <pair<int,int> > it;                      //dont works !!!!
// multiset <int,int>::iterator itr1;                      //dont works !!!!
multiset <pair<int,int> >::iterator itr2;
// multiset <int, int,greater <int> > :: iterator pos1;       //dont works !!!!
// multiset <int,greater <int> > :: iterator pos2;              //dont works !!!!


int id,q,t;
int qcount,psum;
pair <int,int> p;
vector <tuple<int,int,int> > csf;
vector <tuple<int,int,int> > result;
vector<tuple<int, int, int> > v;
void f(){
    
}

int main()
{   
    cin>>n;
    cout<<n<<endl;
    getline(cin,s);
    getline(cin,s);
    for(i=0;i<n;i++){
        cs.clear();
        is.clear();
        allid.clear();
        getline(cin,s);
        while(s.length()){
            sscanf (s.c_str(),"%d %d %d %c",&id,&q,&t,&c);
            cout<<id<<" "<<q<<" "<<t<<" "<<c<<endl;
            
            p = {id,q};
            allid.insert(id);
            if(c=='I'){
                // it=cs.begin();
                // itr1=cs.begin();
                // itr2=cs.begin();         //only this works!!!!
                // pos1=cs.begin();
                // pos2=cs.begin();
                itr2 = cs.find(p);
                if(*itr2!=p){ //push it not solved
                    is.insert(p);
                }
            }else if(c=='C'){
                if(*cs.find(p)!=p){ //if not already solved
                    itr2 = is.find(p);
                    while(*itr2==p){ //calculated penalty it solved
                        t+=20;
                        is.erase(*is.find(p));
                        itr2 = is.find(p);
                    }
                    // cs.insert(p);
                    solvedq.insert(q);
                    solvedid.insert(id);
                    csf.push_back(make_tuple(id,q,t));
                }
            }
            getline(cin,s);
        }

        for (itr3=allid.begin(); itr3!=allid.end(); ++itr3){
            id = *itr3;
            qsum=0;
            psum=0;
            if(*solvedid.find(id)==id){//for id solved some q
                for (itr4=solvedq.begin(); itr4!=solvedq.end(); ++itr4){//combining with all solvedq and if it is in cs
                    q = *itr4;
                    p = {id,q};
                    if(*cs.find(p)==p){ //and if it is in cs
                        qsum++;
                        for(j=0;j<csf.size();j++){
                            if(get<0>(csf[j])==id && get<1>(csf[j])==q){
                                psum+=get<2>(csf[j]);
                            }
                        }
                    }
                }
            }
            result.push_back(make_tuple(id,qsum,psum));
        }
        
        cout<<"**********result***********"<<endl;
        for(j=0; j<result.size();j++){
            cout<<get<0>(result[j])<<" "<<get<1>(result[j])<<" "<<get<2>(result[j])<<endl;
        }
        cout<<endl;
    }
    return 0;
}