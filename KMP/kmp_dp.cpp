#include<iostream>
#include<vector>
#include<string>
using namespace std ;

void getNext( string& pat,vector<int>& next ){
	int i = 1 ;
	int j = -1 ;
	while(i<pat.size()){
		// if( next[i-1]==-1 && pat[next[i-1]]==pat[i-1] ){
		// 	next[i] = 0 ;
		// }
		if( next[i-1]!=-1 && pat[next[i-1]]==pat[i-1] ){
			next[i] = next[i-1]+1 ;
			// j = next[]
		}
		else{
			// j = -1 ;
			next[i] = -1 ;
		}
	}
}

void kmp(string& txt,string&pat ){
	vector<int> next(pat.size(),-1) ;
	getNext(pat,next) ;

	for( int i=0;i<txt.size();++i ){
		bool flag = false ;
		for( int j=0;j<pat.size();++j ){
			if( txt[i] == pat[j] ){
				
			}
		}
	}
}

int main(){
	string txt ;
	string pat ;
	cin>>txt>>pat ;

}