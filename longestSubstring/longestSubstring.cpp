#include<iostream>
#include<string>
using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	if( s.size() == 0 ){
    		return 0 ;
    	}

        int count = 0 ;

        //子串的开始位置和结束位置
        int start = 0 ;
        int end = start ;

        //用于记录字符字符是否在子串中，以及出现的位置
        int table[130][2] = {0};

        for( int i=0;i<s.size();++i ){

        	// '\0'是ASCLL表的第一个字符
        	int p = s[i] - '\0' ;

        	// cout<<"P "<<p<<endl ;

        	if( table[p][0] == 0 ){

        		++table[p][0] ; 
        		// cout<<table[p][0]<<endl ;
        		table[p][1] = i ;

        		//更新end的位置
        		end = i ;
        	}
        	else{
        		// end = i-1 ;
        		// cout<<"start "<<start<<endl ; 
        		// cout<<"end "<<end<<endl ;

        		//计算当前子串长度
        		int tmp = end - start + 1 ;
        		if( tmp > count ){
        			count = tmp ;
        		}

        		// cout<<"count "<<count<<endl ;
        		// cout<<endl ;

        		//定位与当前位置字符相同的上一个点的位置
        		int repeat = table[p][1] ;
        		// cout<<"repeat "<<repeat<<endl ;

        		//更新当前这个字符串出现的位置
        		table[p][1] = i ;

        		//更新table，在repeat之前的都重置为0
        		for( int k=start;k<repeat;++k ){
        			p = s[k] - '\0' ;
        			// cout<<"P "<<p<<endl ;
        			table[p][0] = 0 ;
        			table[p][1] = 0 ;
        		}

        		//更新子串的起始位置，start的值在前面有用到，所以放在最后更新
        		start = repeat + 1 ;
        	}
        }

        //如果最后一个字符不与前面的字符相同，则不会进入else，也就没有更新count
        //所以需要最后更新一次
        int tmp = end - start + 1 ;
		if( tmp > count ){
			count = tmp ;
		}

        return count ;
    }

};

int main(){

	string str = "^$^!@!eacf" ;

	Solution s ;

	int res = s.lengthOfLongestSubstring(str) ;

	cout<<res<<endl ;

	return 0 ;
}