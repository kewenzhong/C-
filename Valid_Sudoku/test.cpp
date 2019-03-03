#include<iostream>
#include<vector>
using namespace std ;

int main(){

	int (*p)[3] ;
	int a[4][3] ;

	for( int i=0;i<12;i++ ){
		a[i/4][i%3] = i ;
	}

	p = a ;

	cout<<p[1][2]<<endl ;

	return 0 ;
}