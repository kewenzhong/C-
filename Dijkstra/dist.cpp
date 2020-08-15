#include <iostream>
using namespace std ;

int graph[100][100] ;

void dist(int n,int s){
	bool record[n] ;
	for( int i=0;i<n;++i ){
		record[i] = false ;
	}
	record[s] = true ;

	for(int j=1;j<n;++j ){
		int k = 0 ;
		int min = 0x7fff ;
		for( int i=0;i<n;++i ){
			if(!record[i] && graph[s][i]<min){
				min = graph[s][i] ;
				k = i ;
			}
		}
		record[k] = true ;

		for( int i=0;i<n;++i ){
			if( !record[i] && graph[s][i]>graph[s][k]+graph[k][i] ){
				graph[i][s] = graph[s][i] = graph[s][k]+graph[k][i] ;
			}
		}
	}

}


int main(){
	int n,m ;
	cin>>n>>m ;
	int points[n] ;
	// int graph[n][n] ;

	for(int i=0;i<n;++i ){
		for( int j=0;j<n;++j )
			graph[i][j] = 0x7fff ;
	}

	for( int i=0;i<n;++i ){
		int src,des,val ;
		cin>>src>>des>>val ;
		graph[src][des] = val ;
		graph[des][src] = val ;
	}

	dist(n,0) ;

	for( int i=0;i<m;++i ){
		if(i!=0){
			cout<<0<<"-->"<<i<<"  "<<graph[0][i]<<endl;
		}
	}

	return 0 ;
}