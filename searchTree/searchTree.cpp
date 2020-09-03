#include <iostream>
using namespace std ;

struct TreeNode{
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* insertNode(TreeNode* root,int e){
	if(root == NULL ){
		TreeNode* node = new TreeNode(e) ;
		root = node ;
		return root ;
	}
	if( e<root->val ){
		root->left = insertNode(root->left,e) ;
	}
	else{
		root->right = insertNode(root->right,e) ;
	}
	return root ;
}

TreeNode* insertNode1(TreeNode* root,int e){
	TreeNode* node = new TreeNode(e) ;
	if(root == NULL ){
		root = node ;
		return root ;
	}
	TreeNode* p = root ;
	while( p ){
		if( e<p->val ){
			if( p->left ){
				p = p->left ;
			}
			else{
				p->left = node ;
				return root ;
			}
		}
		else{
			if( p->right ){
				p = p->right ;
			}
			else{
				p->right = node ;
				return root ;
			}
		}
	}
	return root ;
}

TreeNode* findMaxNode(TreeNode* root){
	while(root->right){
		root = root->right ;
	}
	return root ;
}

TreeNode* findMinNode(TreeNode* root){
	while(root->left){
		root = root->left ;
	}
	return root ;
}


TreeNode* deleteNode(TreeNode* root,int e){
	if( root ==NULL ){
		return NULL ;
	}
	if( e==root->val ){
		if( root->left == NULL && root->right ==NULL ){
			delete root ;
			return NULL ;
		}
		else if( root->right ==NULL ){
			TreeNode*maxNode = findMaxNode(root->left) ;
			root->val = maxNode->val ;
			root->left = deleteNode(root->left,maxNode->val) ;
			return root ;
		}
		else if(root->right ){
			TreeNode*minNode = findMinNode(root->right) ;
			root->val = minNode->val ;
			root->right = deleteNode(root->right,minNode->val) ;
			return root ;
		}
	}
	if( e<root->val ){
		root->left = deleteNode(root->left,e) ;
	}
	else{
		root->right = deleteNode(root->right,e) ;
	}
	return root ;
}

void inTravel(TreeNode* root){
	if( root== NULL ){
		return ;
	}
	if( root->left ){
		inTravel(root->left) ;
	}
	cout<<root->val<<" " ;

	if(root->right){
		inTravel(root->right) ;
	}
}

void freeTree(TreeNode* root){
	if( root==NULL ){
		return ;
	}
	if( root->left ){
		freeTree(root->left) ;
	}
	if( root->right ){
		freeTree(root->right ) ;
	}
	delete root  ;
}

void findSum( TreeNode* root ,int sum ){
	
}

int main(){
	int count ;
	int e  ;
	TreeNode* root = NULL ;

	cin>>count ;
	for( int i=0;i<count;++i ){
		cin>>e ;
		root = insertNode1(root,e) ;
	}
	inTravel(root) ;
	cin>>e ;
	deleteNode(root,e) ;
	inTravel(root) ;
	freeTree(root) ;
	return 0 ;
}