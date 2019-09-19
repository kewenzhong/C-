#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std ;

class Solution{
private :
	int reachable[605][605] = {-1}; 
	int N,M ;
	int X,Y,Z,W ;

public:
	Solution( int N,int M,int x,int y,int z,int w){
		this->N = N ;
		this->M = M ;
		this->X = x ;
		this->Y = y ;
		this->Z = z ;
		this->W = w ;

		for( int i=0;i<600;i++ ){
			for( int j=0;j<600;j++ ){
				reachable[i][j] = -1 ;
			}
		}
	}
	int climb( int mountains[600][600],int x,int y ){
		// cout<<x<<" "<<y<<endl ;

		// for( int i=0;i<10;i++ ){
		// 	for( int j=0;j<30;j++ ){
		// 		cout<<reachable[i][j]<<endl ;
		// 	}
		// }

		if( x == Z && y == W ){
			return 1 ;
		}
		if( reachable[x][y] != -1 ){
			return reachable[x][y];
		}
		int flag = 0 ;
		if( x-1 >= 0 && mountains[x-1][y] > mountains[x][y] ){
			
			flag += climb(mountains,x-1,y) ;
		}
		if( y+1<N && mountains[x][y+1] > mountains[x][y]  ){
			// flag++ ;
			flag += climb(mountains,x,y+1) ;
		}
		if( y-1 >= 0 && mountains[x][y-1] > mountains[x][y]  ){
			// flag++ ;
			flag += climb(mountains,x,y-1) ;
		}
		if( x+1 < M && mountains[x+1][y] > mountains[x][y] ){
			// flag++ ;
			flag += climb(mountains,x+1,y ) ;
		}
		reachable[x][y] = flag ;

		return flag ;

	}

} ;

int main(){

	int n,m ;
	int mountains[600][600] ;
	int x,y,z,w ;

	cin>>n>>m ;

	for( int i=0;i<n;i++ ){
		for( int j=0;j<m;j++ ){
			cin>>mountains[i][j] ;
		}
	}
	cin>>x>>y>>z>>w ;

	Solution s(n,m,x,y,z,w) ;
	cout<<s.climb(mountains,x,y)<<endl ; ;
	return 0 ;
}