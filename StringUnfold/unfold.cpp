#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std ;

struct retValue
{	
	string str ;
	int end ;
};

class Solution{
// private:
// 	string res = "" ;
public:
	retValue unfold(string s,int start,int digit){
		// int l,r ;
		retValue retV = {"",0};
		for( int i=start;i<s.size();i++ ){
			if( !isdigit(s[i]) && s[i] != ')' && s[i] != ']' && s[i] != '}'){
				// res += s[i] ;
				retV.str += s[i] ;
			}
			else if(isdigit(s[i])){
				int digit = s[i] - '0' ;
				retValue subRetV = unfold(s,i+2,digit) ;
				retV.str += subRetV.str ;
				i = subRetV.end ;
				
			}
			else{
				string tmp = "" ;
				for( int j=0;j<digit;j++ ){
					tmp += retV.str ;
				}
				retV.str = tmp ;
				retV.end = i ;
				return retV ;
			}
		}
		return retV ;
	}
};

int main(){
	Solution s ;
	string str ;
	cin>>str ;

	retValue retV = s.unfold(str,0,1) ;

	// string str = retV.str ;
	reverse(retV.str.begin(),retV.str.end()) ;

	cout<<retV.str<<endl ;
	

	return 0 ;
}