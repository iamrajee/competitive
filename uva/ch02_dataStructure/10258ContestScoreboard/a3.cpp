#include<bits/stdc++.h>
#include<tuple>

using namespace std;
int n,i,j,k;
char c;
string s;
int qsum;

set <pair<int,int> > cs;
multiset <pair<int,int> > is;
set <int> allid;
set <int> solvedq;
set <int> solvedid;
set <int>::iterator itr3;
set <int>::iterator itr4;


multiset <pair<int,int> >::iterator itr2;
int id,q,t;
int qcount,psum;
pair <int,int> p;
vector <tuple<int,int,int> > csf;
vector <tuple<int,int,int> > result;

bool sortbysec(const tuple<int, int, int>& a, const tuple<int, int, int>& b){   
    if(get<1>(a) > get<1>(b)){
        return true;
    }else if(get<1>(a) == get<1>(b)){
        if(get<2>(a) < get<2>(b)){
            return true;
        }else if(get<0>(a) < get<0>(b) && get<2>(a) == get<2>(b)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    // return (get<1>(a) > get<1>(b));
} 

int main()
{   
    cin>>n;
    // cout<<n<<endl;
    getline(cin,s);
    getline(cin,s);
    for(i=0;i<n;i++){
        cs.clear();
        is.clear();

        csf.clear();
        result.clear();

        allid.clear();
        solvedid.clear();
        solvedq.clear();

        getline(cin,s);
        while(s.length()){
            sscanf (s.c_str(),"%d %d %d %c",&id,&q,&t,&c);
            // cout<<id<<" "<<q<<" "<<t<<" "<<c<<endl;
            
            p = {id,q};
            allid.insert(id);
            if(c=='I'){
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
                    cs.insert(p);
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
        
        sort(result.begin(), result.end(), sortbysec);
        // sort(result.begin(), result.end(), sortbysec);

        // cout<<"**********result***********"<<endl;
        for(j=0; j<result.size();j++){
            cout<<get<0>(result[j])<<" "<<get<1>(result[j])<<" "<<get<2>(result[j])<<endl;
        }
        // cout<<get<0>(result[j])<<" "<<get<1>(result[j])<<" "<<get<2>(result[j])<<endl;
        if(i!=n-1){
            cout<<endl;
        }
        
    }
    return 0;
}