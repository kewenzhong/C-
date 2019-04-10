#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std ;

vector<int> takeBalls( const vector<int>& balls_1,const vector<int>& balls_2,int b1,int b2,int flag ){
	int tmp ;
	vector<int> score1 ;
	vector<int> score2 ;

	// int score ;


	//妞妞拿球
	if( flag == 0 ){
		tmp = balls_1[b1] ; 
		score1 = takeBalls(balls_1,balls_2,b1+1,b2 ) ;
		score1[0] += tmp ;

		score2 = takeBalls(balls_1,balls_2,b1,b2+1 ) ;

		if( score1[0] - score1[1] > score2[0] - score2[1] ){
			return score1 ;
		}
		else{ 
			return score2 ;
		}
	}
	else{ //牛牛拿球

	}
	




}


bool cmp( int a,int b ){
	return a>b ;
}

void ballGame( vector<int>& balls_1,vector<int>& balls_2 ){
	sort( balls_1.begin(),balls_1.end(),cmp) ;
	sort( balls_2.begin(),balls_2.end(),cmp) ;


}

int main(){
	return 0 ;
}