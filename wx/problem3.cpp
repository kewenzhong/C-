#include <iostream>
#include <vector>
#include <iomanip>
using namespace std ;

struct advertise{
    int no ;
    int p ;
} ;

void problem3(){
    int n ;
    cin>>n ;
    vector<advertise> ads(n) ;

    for( int i=0;i<n;++i ){
        ads[i].no = i+1 ;
        cin>>ads[i].p ;
    }
    sort(ads.begin(),ads.end(),[](const advertise adv1,const advertise adv2){return adv1.p>adv2.p ;}) ;

    while( 1 ){
        vector<int> ad(2) ;
        int count = 1 ;
        for( int i=0;i<n && count>=0;++i ){
            if( ads[i].p>0 ){
                ad[count--] = ads[i].no ;
                ads[i].p-- ;
            }
        }
        if( count==1 ){
            break ;
        } 
        cout<<ad[0]<<" "<<ad[1]<<endl ; 
    }
}

int main(){
    problem3() ;
    return 0;
}