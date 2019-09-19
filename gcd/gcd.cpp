#include<iostream>
using namespace std ;

int gcd(int a,int b){
	return b==0 ? a : gcd(b,a%b) ;
}

int main(){
	int a , b ;

	cin>>a>>b ;

	int res = gcd(a,b) ;

	cout<<res<<endl ;

	return 0 ;
}