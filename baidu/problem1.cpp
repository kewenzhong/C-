#include <iostream>
#include <vector>
#include <iomanip>
using namespace std ;

void problem1(){
    int T ;
    cin>>T ;
    
    while(T--){
        int L,n ;
        cin>>L>>n ;

        vector<int> record(L+1,0) ;
        for( int i=0;i<n;++i ){
            int l,r ;
            cin>>l>>r ;
            
            for( int j=l;j<=r;++j ){
                ++record[j] ;
            }
        }
        for( int i=1;i<=L;++i ){
            cout<<record[i]<<" " ;
        }cout<<endl ;
    } 
}

int main(){
    problem1() ;
    return 0;
}