#include <iostream>
#include <vector>
using namespace std ;

void sort(vector<int>& nums,int L,int R ){
	if( R<= L ){
		return ;
	}
	int l=L,r=R ;
	int soider = nums[l] ;
	while( r>l ){
		while( r>l ){
			if( nums[r]<soider ){
				nums[l++] = nums[r] ;
				break ;
			}
			r-- ;
		}
		while( r>l ){
			if( nums[l]>soider ){
				nums[r--] = nums[l] ;
				break ;
			}
			l++ ;
		}
	}
	nums[l] = soider ;
	sort(nums,L,l) ;
	sort(nums,l+1,R) ;
}

void fastSort( vector<int>& nums ){
	if( nums.size()<2 ){
		return ;
	}
	sort(nums,0,nums.size()-1) ;
}

int main(){
	vector<int> nums ;
	int count,a ;
	cin>>count ;
	for( int i=0;i<count;++i ){
		cin>>a ;
		nums.push_back(a) ;
	}
	fastSort(nums) ;
	for( int i=0;i<nums.size();++i ){
		cout<<nums[i]<<" " ;
	}cout<<endl ;
	return 0 ;
}