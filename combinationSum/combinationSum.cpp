#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res ;

		auto size = candidates.size() ;
        vector<int> ar;

        aResult(candidates,0,target,ar,res) ;
        
        return res ;
    }

    void aResult(vector<int> candidates,int it, int& target,vector<int>& ar,vector<vector<int>>& res){

        for( int i=it;i<candidates.size();i++ ){

        	if( target >= candidates[i] ){

        		ar.push_back(candidates[i]) ;
        		target -= candidates[i] ;

        		if( target == 0 ){
        			res.push_back(ar) ;

//         			ar.pop_back() ;
//         			target += candidates[i] ;
                    
        			// return ;
        		}
                
        		aResult(candidates,i,target,ar,res) ;

        		ar.pop_back() ;
        		target += candidates[i] ;
        	
        	}
        }
        
        // return ar ;
    }
};