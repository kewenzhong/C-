#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std ;

struct TreeNode{
	int val ;
	TreeNode *left ;
	TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL){} ;
} ;


void inorder_noRecur(TreeNode* root){
	stack<TreeNode*> stk ;
	TreeNode *cur = root ;

	while(!stk.empty() || cur ){
		// TreeNode *cur = stk.top() ;
		if(cur){
			stk.push(cur) ;
			cur = cur->left ;
		}
		else{
			cur = stk.top() ;
			stk.pop() ;
			cout<<cur->val<<" " ;
			cur = cur->right ;
		}
	}
	cout<<endl ;
}


void preorder_noRecur(TreeNode* root){
	stack<TreeNode*> stk ;
	TreeNode *cur = root ;

	while(cur || !stk.empty()){
		if(cur){
			cout<<cur->val<<" " ;
			stk.push(cur) ;
			cur = cur->left ;
		}
		else{
			cur = stk.top()->right ;
			stk.pop() ;
		}
	}
}

void postOrder(TreeNode* root){
	stack<TreeNode*> stk ;
	stk.push(root) ;
	TreeNode* cur = root ;
	TreeNode* pre = NULL ;

	while( !stk.empty() ){
		cur = stk.top() ;

		if( (cur->left==NULL && cur->right==NULL) || (pre && (pre==cur->left || pre==cur->right))){
			cout<<cur->val<<" " ;
			pre = cur ;
			stk.pop() ;
		}
		else{
			if(cur->right)
				stk.push(cur->right) ;
			if(cur->left)
				stk.push(cur->left) ;
		}
	}

}

TreeNode* buildTree(vector<int>& array){
	TreeNode* root = NULL ;
	for( int i=0;i<array.size();++i ){
		if(!root){
			root = new TreeNode(array[i]) ;
		}
		else{
			TreeNode* cur = root ;
			TreeNode* father = root ;
			while(cur){
				father = cur ;
				if(array[i]<father->val){
					cur = father->left ;
				}
				else{
					cur = father->right ;
				}
			}
			if(array[i]<father->val){
				father->left = new TreeNode(array[i]) ; 
			}
			else{
				father->right = new TreeNode(array[i]) ;
			}
		}
	}
	return root ;
}

void deleteTree(TreeNode* root){
	if(!root)
		return ;
	deleteTree(root->left) ;
	deleteTree(root->right) ;
	delete root ;
}

int main(){
	vector<int> array = {1,2,6,3,4,5} ;
	TreeNode* root = buildTree(array) ;
	postOrder(root) ;
	deleteTree(root) ;

	return 0 ;
}