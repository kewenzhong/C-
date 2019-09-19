#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std ;

class Solution {
public:
    bool isMatch(string s, string p) {
    	int L,R,l,r ;
    	L = 0 ;
    	l = 0 ;
    	for( int i=0,j=0;i<s.size() && j<p.size(); ){
    		if( p[j] == '*' ){
    			j++ ;
    		}
    	}
    }

    bool isSubMatch( const string subs,const string subp ){

    }
};

int main(){

	return 0 ;
}