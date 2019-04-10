#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
using namespace std ;

void getNext( vector<int>& next,const string& patten ){
	next[0] = 0 ;	
	int k = 0 ; //K值记录的是模式串当前位置前后缀长度

	for( int i=1;i<patten.size();++i ){
		while( k > 0 && patten[i] != patten[k] ){
			k = next[k-1] ;
		}
		if( patten[i] == patten[k] ){
			k++ ;
		}
		next[i] = k ;
	}
}

//ababababc
//abababc

int kmp( const string& str , const string& patten ){
	vector<int> next ;
	next.resize( patten.size() ) ;
	getNext(next,patten) ;

	int i=0,j=0,k=0 ;
	while( i<str.size() ){
		//找到模式串目标串第一个不匹配的位置，j记录模式串的位置，k记录目标串的位置
		while( k<str.size() && j<patten.size() && patten[j] == str[k] ){
			k++ ;
			j++ ;
		}
		//如果模式串已经比较完了，则说明在目标串匹配成功
		if( j == patten.size() ){
			return i ;
		}
		//如果目标串已经到达了末尾，但是还是没有匹配到模式串，则说明匹配失败，返回-1
		if( k == str.size()-1 ){
			return -1 ;
		}

		//模式串与目标串不匹配时
		if( patten[j] != str[k] ){
			/**	这里就要用到前缀后缀的原理
			*	模式串的当前位于目标串的当前位不匹配，但是当前位置之前的 j 位是
			*	与目标串的前 j 位匹配的（c语言下标从0开始）。那么我们就可以利用
			*	模式串的前 j 位的部分匹配表。
			*/
			if( j>0){	
				i += j-next[j-1] ;
				j = next[j-1] ;
			}
			//如果模式串第一位就要目标串不匹配，则直接与目标串的下一位比较
			else{		
				i++ ;
			}
		}

	}
	return -1 ;
	
}


int main(){

	string str = "ababababc" ;
	string patten = "abca" ;

	int res = kmp(str,patten) ;
	cout<<res<<endl ;

	return 0 ;
}