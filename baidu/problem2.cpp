#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std ;

void problem2(){
    int T ;
    cin>>T ;
    
    while(T--){
        int n,m ;
        cin>>n>>m ;

        vector<int> actor(n) ;
        vector<int> role(m) ;
        vector<bool> flag(m,false) ;
        vector<int> res(n,-1) ;

        for( int i=0;i<n;++i ){
            cin>>actor[i] ; 
        }
        for( int i=0;i<m;++i ){
            cin>>role[i] ; 
        }

        sort(role.begin(),role.end()) ;

        for( int i=0;i<n;++i ){
            for( int j=0;j<m;++j ){
                if( role[j]>=actor[i] && !flag[j] ){
                    res[i] = j+1 ;
                    flag[j] = true ;
                    break ;
                }
            }
        }
        for( auto a:res ){
            cout<<a<<" " ;
        }cout<<endl ;
    } 
}

int main(){
    problem2() ;
    return 0;
}