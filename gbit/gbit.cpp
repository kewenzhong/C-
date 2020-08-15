#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cmath>
using namespace std ;

int problem1(){
	int n ;
	cin>>n ;

	int start ;
	if( n%2==0 ){
		start = n-1 ;
	}
	else{
		start = n ;
	}

	int res1,res2 ; 
	for( int i = start;i>1;i-=2 ){
		int flag = 0 ;
		for( int j=3;j<=sqrt(i);j+=2 ){
			if(i%j==0){
				flag = 1 ;
			}
		}
		if(flag==0){
			// return i ;
			res1 = i ;
			break ;
		}
	}

	if( n%2==0 ){
		start = n+1 ;
	} 
	else{
		start = n ;
	}
	for( int i=start;;i+=2 ){
		int flag = 0 ;
		for( int j=3;j<=sqrt(i);j+=2 ){
			if( i%j==0 ){
				flag = 1 ;
			}
		}
		if(flag==0){
			// return i ;
			res2 = i ;
			break ;
		}
	}

	return abs(res1-n)<=abs(res2-n)?res1:res2 ;
}

void swap(string& s,int i,int j){
	char c = s[i] ;
	s[i] = s[j] ;
	s[j] = c ;
}

long long stoi(string& s){
	long long res = 0 ;
	for( int i=0;i<s.size();++i ){
		res *= 10 ;
		res += s[i] - '0' ;
	}
	return res ;
}	

// int count = 0 ;

void dfs(string& s,int k,const int m,int& count){
	if(k==s.size()-1){
		long long num = stoi(s) ; 
		
		if( num%m == 0 ){
			++count ;
			// cout<<num<<endl  ;
			// cout<<count<<endl;
		}
		return ;
	}

	for( int i=k;i<s.size();++i ){
		swap(s,i,k) ;
		dfs(s,k+1,m,count) ;
		swap(s,i,k) ;
	}

}

int problem2(){
	string s ;
	int m ;
	int count = 0 ;
	unordered_set<string> uset ;

	cin>>s ;
	cin>>m ;

	// cout<<s<<m<<endl ;
	dfs(s,0,m,count) ;

	return count ;
}

int main(){
	int res = problem1() ;
	cout<<res<<endl ;
	return 0 ;

}