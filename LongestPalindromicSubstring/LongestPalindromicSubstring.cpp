#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std ;

class Solution {
public:
	
    string longestPalindrome(string s) {
    	if( s.size() <= 1 ){
    		return s ;
    	}
    	string res = "" ;
    	for( int i=0;i<s.size()-1;i++ ){
    		string fp1 = findPalindrome(s,i,i) ;
    		string fp2 = findPalindrome(s,i,i+1) ;
    		string s = fp1.size()>fp2.size()?fp1:fp2 ;
    		res = res.size()>s.size()?res:s ;
    	}
    	return res ;
    }

    string findPalindrome( string s,int left,int right ){
    	while( left>=0 && right<s.size() && s[left] == s[right] ){
    		left-- ;
    		right++ ;
    	}
    	return s.substr(left+1,right-left-1) ;
    }
};


int main(){

	string str ;
	cin>>str ;

	Solution solu ;
	cout<<solu.longestPalindrome(str)<<endl ;

	return 0 ;
}