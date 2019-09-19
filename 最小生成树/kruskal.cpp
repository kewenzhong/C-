#include<iostream>
#include<vector>
using namespace std ;
#define MAX_INT 65535	

vector<vector<int>> graph(100,vector<int>(3,0));
vector<int> father ;
vector<bool> edgeused(100,false) ;
vector<bool> edgechoosen(100,false) ;

int node,edge ;

int findRoot( int node ){
	return node==father[node]?node:findRoot(father[node]) ;
}

void createGraph(){
	cin>>node>>edge ;

	father.resize(node+1) ;
	// graph.resize(edge) ;

	for( int i=1;i<=node;++i ){
		father[i] = i ;
	}
	// int source,des,cost ;
	for( int i=0;i<edge;++i ){
		cin>>graph[i][0]>>graph[i][1]>>graph[i][2] ;
	}	

}

void kruskal(){
	int count = 0 ;
	while(count<node-1){
		int minEdge = MAX_INT,point = 0 ;
		for( int i=0;i<edge;++i ){
			if( graph[i][2] < minEdge && edgeused[i] == false ){
				minEdge = graph[i][2] ;
				point = i ;
			}
		}

		edgeused[point] = true ;
		if( findRoot(graph[point][0]) != findRoot(graph[point][1])){
			edgechoosen[point] = true ;
			++count ;
		}

		father[findRoot(graph[point][0])] = father[findRoot(graph[point][1])] ;
	}

	for( int i=0;i<edge;++i ){
		if(edgechoosen[i]){
			cout<<graph[i][0]<<"------->"<<graph[i][1]<<"        "<<graph[i][2]<<endl ;
		}
	}
	
}

int main(){
	createGraph() ;
	kruskal() ;
	return 0 ;
}