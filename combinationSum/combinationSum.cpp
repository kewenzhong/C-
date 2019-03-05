#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res ;

		auto size = candidates.size() ;
		// vector<int> ar ;
		// for( auto i=0;i<size;i++ ){

			// vector<int> candidate(candidates.begin()+i,candidates.end()) ;
			vector<int> ar;
			int target_ = target ;

            aResult(candidates,0,target_,ar,res) ;
			// if( !target_ && ar[0] == candidates[i] ){
			// 	res.push_back(ar) ;
			// }
		// }
        return res ;
    }

    void aResult(vector<int> candidates,int it, int& target,vector<int>& ar,vector<vector<int>>& res){

        for( int i=it;i<candidates.size();i++ ){

        	if( target >= candidates[i] ){

        		ar.push_back(candidates[i]) ;
        		target -= candidates[i] ;

        		if( target == 0 ){
        			res.push_back(ar) ;

        			ar.pop_back() ;
        			target += candidates[i] ;

        			return ;
        		}
        		// vector<int> tmp = 
        		aResult(candidates,i,target,ar,res) ;

        		// if( target ){
        		ar.pop_back() ;
        		target += candidates[i] ;
        		// }

        	}
        	// else if( target == candidates[i] ){

        	// 	target -= candidates[i] ;
        	// 	ar.push_back(candidates[i]) ;

        	// 	if( ar[0] == candidates[it] ){
        	// 		res.push_back(ar) ;
                    
        	// 	}

        	// 	ar.pop_back() ;
         //        target += candidates[i] ;
        		
        	// 	// return ar ;
        	// }
        }
        
        // return ar ;
    }
};