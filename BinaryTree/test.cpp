//Definition for a binary tree node.
#include<iostream>
#include<vector>
#include<string>
using namespace std ;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
       	 
//     }
// };

int main(){
	vector<int> node = {1,2,3,4,5,6,7,8,9} ;

	vector<int>::iterator start = node.begin() ;
	vector<int>::iterator end = node.begin()+3 ;

	vector<int> cut_node(start,end) ;

	for( auto el : cut_node ){
		cout<<el<<" " ;
	}
	cout<<endl;

	return 0 ;
	
}