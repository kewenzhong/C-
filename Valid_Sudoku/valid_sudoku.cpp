#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        char a[9];

        for( int i=0;i<9;i++ ){
        	// a[0][i] = 'a'+i ;
        	a[i] = '0' ; 
        }

        //row
        for( int i=0;i<9;i++ ){
        	for( int j=0;j<9;j++ ){
        		if( board[i][j] != '.' ){
        			int num = board[i][j] - '0' ;
        			if( a[num] != '0' ){
        				return false ;
        			}
        			else{
        				a[num] += 1 ;
        			}
        		}
        	}

        	reset(a) ;
        }

        //column
        for( int i=0;i<9;i++ ){
        	for( int j=0;j<9;j++ ){
        		if( board[j][i] != '.' ){
        			int num = board[j][i] - '0' ;
        			if( a[num] != '0' ){
        				return false ;
        			}
        			else{
        				a[num] += 1 ;
        			}
        		}
        	}

        	reset(a) ;
        }

        //each 3x3
        for( int k=0;k<9;k++ ){
        	for( int i=3*(k/3);i<3*(k/3)+3;i++ ){
        		for( int j=3*(k%3);j<3*(k%3)+3;j++ ){
        			if( board[j][i] != '.' ){
        				int num = board[j][i] - '0' ;
        				if( a[num] != '0' ){
        					return false ;
        				}
        				else{
        					a[num] += 1 ;
        				}
        			}

        		}
        	}
        }

        return true ;
    }

    void reset(char *a){
    	for( int i=0;i<9;i++ ){
    		a[i] = '0' ;
    	}
    }
};

int main(){
	// vector<vector<char> > board ;
	// char c[9][9] = {
	// 	{"5","3",".",".","7",".",".",".","."},
	//   {"6",".",".","1","9","5",".",".","."},
	//   {".","9","8",".",".",".",".","6","."},
	//   {"8",".",".",".","6",".",".",".","3"},
	//   {"4",".",".","8",".","3",".",".","1"},
	//   {"7",".",".",".","2",".",".",".","6"},
	//   {".","6",".",".",".",".","2","8","."},
	//   {".",".",".","4","1","9",".",".","5"},
	//   {".",".",".",".","8",".",".","7","9"}
	// } ;

	vector<vector<char> > board =([
	  ["5","3",".",".","7",".",".",".","."],
	  ["6",".",".","1","9","5",".",".","."],
	  [".","9","8",".",".",".",".","6","."],
	  ["8",".",".",".","6",".",".",".","3"],
	  ["4",".",".","8",".","3",".",".","1"],
	  ["7",".",".",".","2",".",".",".","6"],
	  [".","6",".",".",".",".","2","8","."],
	  [".",".",".","4","1","9",".",".","5"],
	  [".",".",".",".","8",".",".","7","9"]
	]) ;

	Solution solu ;

	bool res = solu.isValidSudoku(board) ;


	return 0 ;
}




