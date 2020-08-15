#include <iostream>
#include <vector>
using namespace std ;

void sort(vector<int>& nums,int L,int R){
	if( R<=L ){
		return ;
	}
	vector<int> tmp ;
	for( int i=L;i<=R;++i ){
		tmp.push_back(nums[i]) ;
	}
	int mid = (tmp.size()-1)/2 ;
	sort(tmp,0,mid) ;
	sort(tmp,mid+1,tmp.size()-1) ;

	int l=0,r=mid+1 ;
	int p = L ;
	while( l<=mid && r<=tmp.size()-1){
		if( tmp[l]<tmp[r] ){
			nums[p++] = tmp[l++] ;
		}
		else{
			nums[p++] = tmp[r++] ;
		}
	}
	while( l<=mid ){
		nums[p++] = tmp[l++] ;
	}
	while( r<=tmp.size()-1){
		nums[p++] = tmp[r++] ;
	}
}

void mergeSort(vector<int>& nums){
	if( nums.size()<2 ){
		return ;
	}
	sort(nums,0,nums.size()-1) ;
}

int main(){
	vector<int> nums ;
	int count,a;
	cin>>count ;
	for( int i=0;i<count;++i ){
		cin>>a ;
		nums.push_back(a) ;
	}
	mergeSort(nums) ;
	for( int i=0;i<nums.size();++i ){
		cout<<nums[i]<<" " ;
	}cout<<endl ;
	return 0 ;
}