#include<iostream>
#include<string>
#include<vector>
using namespace std ;


class Solution {
public:
    long myAtoi(string str) {

 		bool canBeInteger = true ;
 		bool isNegative = false ;
 		string IntegerStr = "" ;
 		long long  res = 0 ;

 		long long int_max = 1 ;
 		long long int_min = -1 ;

 		for( int i=0;i<31;i++ ){
 			int_max *= 2 ;
 		}
 		int_min *= int_max ;
 		int_max -= 1 ;

        int i=0;
        while( i < str.size() ){
        	if( str[i] == ' ' )
        		i++ ;
        	else{
        		break ;
        	}
        }
        // cout<<i<<endl ;
        if( i < str.size() ){
        	if( str[i] == '-' ){
        		isNegative = true ;
        		i++ ;
        	}
        	else if( str[i] == '+' ){
        		isNegative = false ;
        		i++ ;
        	}
        	else if( !isdigit(str[i]) ){
        		canBeInteger = false ;
        		return 0 ;
        	}
        }
        else{
        	return res ; 
        }

        if( canBeInteger ){

        	while( i < str.size() && str[i] == '0' ){
        		i++ ;
        	}

        	if( isdigit(str[i]) ){
        		while( i < str.size() && isdigit(str[i]) ){
	        		IntegerStr.push_back(str[i++]) ;
	        	}
        	}
        	else{
        		return 0 ;
        	}
        	
        	// cout<<IntegerStr<<endl ;

        	if( IntegerStr.size() > 0 && IntegerStr.size() < 11 ){
        		for( int i=0 ;i<IntegerStr.size();++i ){
        			res += (IntegerStr[i] - '0');
        			res *= 10 ;
        			// cout<<res<<endl ;
        		}
        		res /= 10 ;

        		if( isNegative == true ){
        			res *= -1 ;
        		}

        		if( res > int_max ){
        			res = int_max ;
        		}
        		else if( res < int_min ){
        			res = int_min ;
        		}
        	}
        	else if(IntegerStr.size() >= 11) {
        		if( isNegative ){
        			res = int_min ;
        		}
        		else{
        			res = int_max ;
        		}
        	}
        }
        return res ;
    }
};

int main(){
	string str ;

	cin>>str ;

	Solution s ;
	cout<<s.myAtoi(str)<<endl ;


	return 0 ;
}