#include<iostream>
#include<vector>
using namespace std ;

class Solution {
private :
    //record the space cells,and the possible value of the sapce cells 
    // vector<vector<vector<char>>> valid ;
    
public:
    bool solveSudoku(vector<vector<char>>& board) {
        
        for( int i=0;i<9;i++ ){
            for( int j=0;j<9;j++ ){
                
                if( board[i][j] == '.' ){
                    vector<char> av = availableValue(i,j,board) ;
                    
                    if( av.empty() ){
                        // cout<<"empty"<<endl ;
                        return false;
                    }
                    
                    int size = av.size() ;
                
                    for( int k=0;k<size;k++ ){
                        board[i][j] = av[k] ;
                        
                        // printRes(board) ;
                        
                        bool res = solveSudoku(board) ;
                        // cout<<res<<endl ;
                        if( res ){
                            return true ;
                        }
                        else{
                            board[i][j] = '.' ;
                        }
                    }
                    
                    if( board[i][j] == '.' ){
                        return false ;
                    }
                    
                   
                }
            }
        }
        // printRes(board) ;
        return true ;
    }
    
    //find the available value of the specific cell
    vector<char> availableValue(const int x,const int y,const vector<vector<char>>& board){
        int a[10] = {0} ;
        
        for( int i=0;i<9;i++ ){
            if( board[x][i] != '.' ){
                a[board[x][i]-'0'] = 1 ;
            }
        }
        
        for( int i=0;i<9;i++ ){
            if( board[i][y] !='.' ){
                a[board[i][y]-'0'] = 1 ;
            }
        }
        
        int x0 = 3*(x/3) ;
        int y0 = 3*(y/3) ;
        
        for( int i=x0;i<x0+3;i++ ){
            for( int j=y0;j<y0+3;j++ ){
                if( board[i][j] != '.' ){
                     a[board[i][j]-'0'] = 1 ;
                }
            }
        }
        
        vector<char> v ;
        for( int i=1;i<10;i++ ){
            // cout<<a[i]<<" ";
            if( a[i]==0 ){
                v.push_back('0'+i) ;
            }
        }
        // cout<<endl ;
        
        // cout<<"x="<<x+1<<"  y="<<y+1<<endl ;
        // for ( auto i:v ){
        //     cout<<i<<" " ;
        // }
        // cout<<endl ;
        
        return v ;
        
    }
    
    void printRes(const vector<vector<char>>& board){
        for (int i=0;i<9;i++ ){
            for( int j=0;j<9;j++ ){
                cout<<setw(6)<<left<<board[i][j] ;
            }
            cout<<endl ;
        }
        cout<<endl ;
        cout<<endl ;
    }
    
//     //
//     bool isIllegal(int x,int y,char c,vector<vector<char>>& board){
        
//     }
    
//     /*
//     *   initiate the 3D vector,set its height 10 ,width 10
//     *   mark the cells that is not space
//     *   where space cell is marked '1',otherwise '0'
//     */
//     void initValid(vector<vector<vector<char>>>& valid,const vector<vector<char>>& board){
//         valid.resize(10) ;
//         for( int i=0;i<10;i++ ){
//             valid[i].resize(10) ;
//         }
        
//         for( int i=0;i<9;i++ ){
//             for( int j=0;j<9;j++ ){
//                 if( board[i][j] != '.' ){
//                     valid[i][j][0] = '1' ;
//                 }
//                 else{
//                     valid[i][j][0] = '0' ;
//                 }
//             }
//         }
        
//     }
        
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




