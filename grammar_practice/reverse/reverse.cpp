#include<iostream>
#include<string>
#include<cctype>
using namespace std ;

class Solution{
	public :
	bool isPalindrome(string s){
		if( s.empty() )
			return true ;

		int l = 0,r = s.size()-1 ;

		while( r>l ){
			if( isalpha(s[r]) && isalpha(s[l]) ){
				if( tolower(s[r]) == tolower(s[l]) ){
					r-- ;
					l++ ;
				}
				else{
					return false ;
				}
			}

			else if( !isalpha(s[r]) ){
				r-- ;
			}
			else if( !isalpha(s[l]) ){
				l++ ;
			}

		}
		return true ;
	}
} ;


int main(){
	string s ;

	getline(cin,s) ;

	Solution solu ;

	bool res = solu.isPalindrome(s) ;

	cout<<res<<endl ;


	return 0 ;
}