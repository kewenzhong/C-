#include<iostream>
#include<string>
using namespace std ;

int SroundCount( const std::string& str,const std::string& sub ){

	int count = 0;
	int strSize = str.size() ;
	int subSize = sub.size() ;

	for( int i=0;i<strSize;i++ ){

		if( str[i] == sub[0] ){
			int j=1 ;
			int tmp = (i+1)%strSize ;

			while( j<subSize ){

				if( str[tmp] != sub[j] ){
					break ;
				}

				tmp = (tmp+1)%strSize ;
				j++ ;

			}

			if( j == subSize ){
				i += subSize ;
				count++ ;
			}
		}
	}
	return count ;
}

int main(){

	string str,sub ;
	cin>>str>>sub ;

	cout<<SroundCount(str,sub) <<endl ;

}