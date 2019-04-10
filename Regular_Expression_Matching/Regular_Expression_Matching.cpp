#include<iostream>
#include<string>
#include<cctype>
using namespace std ;

class Solution {
public:
    bool isMatch(string s, string p) {
    	// s为空的时候
    	if( s.size() == 0 ){

    	}

    	int i=s.size()-1,j=p.size()-1 ;
    	while( i>=0 && j>=0 ){
    		if( p[j]=='.' ){
    			i-- ;
    			j-- ;
    		}
    		else if( p[j]=='*' ){
    			char c ;
    			// int tmp = j ;
    			j-- ;
    			while( p[j] == p[j-1] ){
    				j-- ;
    			}
    			// c = p[tmp] ;
    			if( s[i]!=p[j] ){
    				return false ;
    			}
    			
    			while( i>=0 && s[i] == p[j] ){
    				i-- ;
    			}

    			j-- ;

    			if( i<0 ){
    				if( j<0 ){
    					return true ;
    				}
    				else if( j>0 && )
    			}
    			

    		}
    		else{

    		}

    	}

        
    }
};

int main(){


	return 0 ;
}