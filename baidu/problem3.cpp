#include <iostream>
#include <vector>
#include <iomanip>
using namespace std ;

long long dp[100000][8][8] = {0} ;
long long MAX = 1e9+7 ;
 
long long step( int n,const int& m,vector<int> history ){
    if( n<0 ){
        return 0 ;
    }
    if( n == 0 ){
        return 1 ;
    }

    if( dp[n][history[0]][history[1]]>0 ){
        return dp[n][history[0]][history[1]] ;
    }

    vector<int> tmp(history) ;
    tmp[0] = tmp[1] ;

    long long res = 0 ;
    for( int i=1;i<=m;++i ){
        if( i==history[0] || i==history[1] ){
            continue ;
        }
        tmp[1] = i ;

        res += step(n-i,m,tmp)%MAX ;
        res %= MAX ;
    }
    
    dp[n][history[0]][history[1]] = res ;
    dp[n][history[1]][history[0]] = res ;
    return res ;
}

void problem3(){
    int n,m ;
    cin>>n>>m ;

    vector<int> history(2,0) ;
    long long res = step(n,m,history)%MAX ;
    cout<<res<<endl ;
}

int main(){
    // cout<<dp[100][4][4]<<endl ;
    problem3() ;
    return 0;
}