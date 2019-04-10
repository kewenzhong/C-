#include<iostream>
using namespace std ;

class Solution {
public:
    int trap(vector<int>& height) {
        int highest = 0 ;
        int count = 0 ;


        for( auto i:height ){
        	if( i> highest ){
        		highest = i ;
        	}
        }

        for( int i=1;i<=highest;i++ ){
        	int l = 0 ;

        	for( int j=0;j<height.size();j++ ){
        		if( height[j]>=i ){
        			l = j ;
        			r = l ;
        		}
        	}

        	for( int j=l+1;j<height.size(); ){
        		if( height[j]>=i ){
        			r = j ;
        			count += r-l+1 ;
        			l = r ;
        			j = l+1 ;
        		}
        		else{
        			j++ ;
        		}
        	}
        }

        return count ;

    }
};


int main(){

	Solution s ;

	

	return 0 ;
}