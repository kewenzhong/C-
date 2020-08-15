#include <iostream>
#include <vector>
using namespace std ;

void swap( vector<int>& array,int i,int j){
	int tmp = array[i] ;
	array[i] = array[j] ;
	array[j] = tmp ;
}

void adjustHeap(vector<int>& array,int len,int index){
	int maxIndex = index ;

	if( index*2+1<len && array[maxIndex]<array[index*2+1] ){
		maxIndex = index*2 + 1 ;
	}
	if( index*2+2<len && array[maxIndex]<array[index*2+2] ){
		maxIndex = index*2 + 2 ;
	}

	if( maxIndex != index ){
		swap(array,maxIndex,index) ;
		adjustHeap( array,len,maxIndex ) ;
	}
}

void heapSort( vector<int>& array ){
	for( int i=(array.size()-1)/2;i>=0;--i ){
		adjustHeap(array,array.size(),i) ;
	} 
	for( auto i:array ){
		cout<<i<<" " ;
	}cout<<endl ;

	for( int i=array.size()-1;i>0;--i ){
		swap( array,0,i) ;
		adjustHeap(array,i,0) ;
	}
}

int main(){
	vector<int> array ;

	int size ;
	cin>>size ;

	for( int i=0;i<size;++i ){
		int e  ;
		cin>>e ;
		array.push_back(e) ;
	}

	heapSort(array) ;

	for( auto i:array ){
		cout<<i<<" " ;
	}cout<<endl ;


	return 0 ;
}