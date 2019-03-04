#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res ;

		auto size = candidates.size() ;
		// vector<int> ar ;
		for( auto i=0;i<size;i++i++ ){

			vector<int> candidate(candidates.begin()+i,candidates.end()) ;
			vector<int> ar;
			int target_ = target ;

            aResult(candidate,target_,ar,res) ;
			// if( !target_ && ar[0] == candidates[i] ){
			// 	res.push_back(ar) ;
			// }
		}
        return res ;
    }

    void aResult(vector<int> candidates, int& target,vector<int>& ar,vector<vector<int>>& res){

        for( auto i:candidates ){
        	if( target>i ){
        		ar.push_back(i) ;
        		target -= i ;
        		// vector<int> tmp = 
        		aResult(candidates,target,ar) ;
        		if( target ){
        			ar.pop_back() ;
        			target += i ;
        		}

        	}
        	else if( target == i ){
        		target -= i ;
        		ar.push_back(i) ;
        		if( ar[0] == candidates[0] )
        			res.push_back(ar) ;
        		// return ar ;
        	}
        }
        
        // return ar ;
    }
};