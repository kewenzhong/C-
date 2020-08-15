#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std ;

class FastSort{

public:
	void swap(int& a ,int& b){
		int tmp  = a ;
		a = b ;
		b = tmp ;
	}

	void fastsort(vector<int>& vecInt,int left,int right){
		if( right<=left ){
			return ;
		}
		int l = left ;
		int r = right ;

		int index = (right+left)/2 ;
		swap(vecInt[index],vecInt[left]) ;
		int soider = vecInt[left] ;

		while(right>left){
			while( right>left && vecInt[right]>=soider ){
				--right ;
			}
			if(vecInt[right] < soider)
				vecInt[left++] = vecInt[right] ;

			while(right>left && vecInt[left]<=soider ){
				++left ;
			} 
			if(vecInt[left]>soider)
				vecInt[right--] = vecInt[left] ;
		} 
		vecInt[left] = soider ;

		fastsort(vecInt,l,left-1) ;
		fastsort(vecInt,left+1,r) ;
	}

} ;

int main(){

	std::vector<int> vctInt;

	int length ;

	cin>>length ;

	int tmp ;
	for( int i=0;i<length;i++ ){
		cin>>tmp ;
		vctInt.push_back(tmp) ;
	}

	FastSort fs ;
	fs.fastsort(vctInt,0,length-1) ;

	for( auto i:vctInt ){
		cout<<i<< " " ;
	}
	cout<<endl ;

	return 0 ;
}