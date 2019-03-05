#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  		//用于记录最后的结果
		vector<vector<int>> res ;

		auto size = candidates.size() ;
		//记录每个单独的解
        vector<int> ar;

        findResult(candidates,0,target,ar,res) ;
        
        return res ;
    }

    /*
    *	findResult(const vector<int> candidates,int it, int target,vector<int>& ar,vector<vector<int>>& res)
    *	candidates:输入的集合
    *	it:当前的起始位置，只能从it向后寻找下一个加数
    *	target:当前目标数，当为0时表示找到了一组答案
    *	ar:用于存储一组解
    *	res:目标答案
    */
    void findResult(const vector<int> candidates,int it, int target,vector<int>& ar,vector<vector<int>>& res){

        for( int i=it;i<candidates.size();i++ ){

        	if( target >= candidates[i] ){

        		ar.push_back(candidates[i]) ;
        		target -= candidates[i] 

        		if( target == 0 ){
        			res.push_back(ar) ;
        		}
                
        		findResult(candidates,i,target,ar,res) ;

        		ar.pop_back() ;
        		target += candidates[i] ;
        	
        	}
        }
        
        // return ar ;
    }
};