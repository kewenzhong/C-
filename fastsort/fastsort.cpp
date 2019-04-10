#include <iostream>
#include <vector>
using namespace std ;

class FastSort{

public:
	void sort( vector<int>& vctInt,int left,int right ){

		if( right <= left ){
			return ;
		}

		// cout<<"left = "<<left<<endl ;
		// cout<<"right = "<<right<<endl ;

		int soldier = vctInt[left] ;

		int l = left ;
		int r = right ;

		while( r>l ){
			while( vctInt[r] >= soldier && r>l ){
				r-- ;
			}
			vctInt[l] = vctInt[r] ;

			while( vctInt[l] <= soldier && r>l ){
				l++ ;
			}

			vctInt[r] = vctInt[l] ;
		}

		vctInt[l] = soldier ;

		sort(vctInt,left,l-1) ;
		sort(vctInt,l+1,right) ;

	}

} ;

int main(){

	std::vector<int> vctInt;

	int length ;

	cin>>length ;

	int tmp ;
	for( auto i=0;i<length;i++ ){
		cin>>tmp ;
		vctInt.push_back(tmp) ;
	}

	FastSort fs ;
	fs.sort(vctInt,0,length-1) ;

	for( auto i:vctInt ){
		cout<<i<< " " ;
	}

	return 0 ;
}