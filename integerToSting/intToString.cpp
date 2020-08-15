#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std ;

int func( int num ){
    vector<int> number ;
    while( num ){
        number.push_back(num%10) ;
        num /=10 ;
    }
    reverse(number.begin(),number.end()) ;
    vector<int> record(number.size(),0) ;

    record[0] = 1 ;
    if( number[0]*10 + number[1] > 25 ){
        record[1] = 1 ;
    }
    else{
        record[1] = 2 ;
    }
    for( int i=2;i<number.size();++i ){
        if( number[i-1]*10 + number[i] > 25 ){
            record[i] = record[i-1] ;
        }
        else{
            record[i] = record[i-1] + record[i-2] ;
        }
    }
    return record[number.size()-1] ;
}

int main(){
    int num ;
    cin>>num ;
    int res = func(num) ;
    cout<<res<<endl ;
    return 0 ;
}