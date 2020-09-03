#include <iostream>
#include <vector>
#include <iomanip>
using namespace std ;

void problem2(){
    int n,m ;
    cin>>n>>m ;

    if( n<2*m-1 ){
        cout<<"error input"<<endl ;
        return ;
    }

    vector<vector<int>> record(n,vector<int>(n)) ; 
    int cur = 1 ;
    for( long long k=0;k<=n/2;++k ){
        // if( k>=m-1 ){
        // int cur = start + 1 ;
        for( int y=k;y<n-k;++y ){
            record[k][y] = cur++ ;
        }
        for( int x=k+1;x<n-k-1;++x ){
            record[x][n-k-1] = cur++ ;
        }
        for( int y=n-k-1;y>=k && cur<=n*n;--y ){
            record[n-k-1][y] = cur++ ;
        }
        for( int x=n-k-2;x>k;--x ){
            record[x][k] = cur++ ;
        }
            // }
    }
    for( int i=m-1;i<2*m-1;++i ){
        for( int j=m-1;j<2*m-1;++j ){
            cout<<setw(2)<<record[i][j]<<" " ;
        }cout<<endl ;
    }
}

int main(){
    problem2() ;
    return 0;
}