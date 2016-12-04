// Author : Priya Ananthasankar
// Goal: Implement a binary tree and determine if it is balanced.
// Commands: g++ 4.1.cpp; ./a.out
#include <iostream>
using namespace std;

struct TreeNode{

	int x;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

class BinaryTree{

 private: 
 	TreeNode* root; TreeNode* start;

 public:

 	BinaryTree(){
 		root = NULL;
 		start = NULL;

 	}

 	void insert(int val){
 		 TreeNode* newNode = new TreeNode();
 		 newNode -> x = val;
 		 //start = root;
 		 if(start == NULL){
 		 	root = newNode;
 		 	start = root;
 		 }else if(start -> left == NULL){
 		 	start-> left = newNode;
 		 }else if(start -> right == NULL){
 		 	start-> right = newNode;
 		 }
		 newNode -> parent = start;
		 if((start != NULL) && (start -> left != NULL) && (start -> right != NULL)){
 		 	start = newNode;
 		 }
 	}

 	void deleteBT(int val){
 		deleteNode(root,NULL,val,"NONE");
 	}

 	void deleteNode(TreeNode* s,TreeNode *par,int val,string side){

 		if(s == NULL){
 			return;
 		}
 		if(s -> x == val){
 			TreeNode* poppedNode = s;
 			if((s -> left != NULL) || (s -> right != NULL)){
 				if(s -> right == NULL){
 					root =  s -> left;
 				}else{
 					if(s -> left -> left != NULL){
 						TreeNode* temp = s -> left -> left;
 						s -> left = s -> right;
 						insert(s -> left -> left -> x);
 						root = s -> left;
 					} else{
 						TreeNode* temp = s -> right;
 						temp -> parent = s -> left;
 						s -> left -> left = s -> right;
 						root = s -> left;
 					}
 				}
 				delete s;
 			}else{
 				if(side == "RIGHT"){
 					par -> right = NULL;
 				}else if(side == "LEFT"){
 					par -> left = NULL;
 				}else{
 					root = NULL;
 				}
 				delete s;
 			}
 		} else{
 			deleteNode(s -> left, s-> parent,val,"LEFT");
 			deleteNode(s -> right, s -> parent,val,"RIGHT");
 		}
 	}

 	bool hasBothChildren(TreeNode* n){
 		if((n -> left != NULL) && (n -> right != NULL)){
 			return true;
 		}
 		return false;
 	}

 	void printPostorder(){
 		printPostOrderTree(root);
 	}

 	void printPreorder(){
 		printPreOrderTree(root);
 	}

 	void printInorder(){
 		printInorderTree(root);
 	}

 	void printInorderTree(TreeNode* root){
 		if(root != NULL){
 			printInorderTree(root -> left);
 			cout << root -> x << " ";
 			printInorderTree(root -> right);
 		}
 	}

 	void printPreOrderTree(TreeNode* root){
 		if(root != NULL){
 			cout << root -> x << " ";
 			printPreOrderTree(root -> left);
 			printPreOrderTree(root -> right);
 		}
 	}

 	void printPostOrderTree(TreeNode* root){
 		if(root != NULL){
 			printPostOrderTree(root -> left);
 			printPostOrderTree(root -> right);
 			cout << root -> x << " ";
 		}
 	}

};	

int main(){
	int n; int item;

	BinaryTree *tree = new BinaryTree();

	cout<< "Enter number of items : " << endl;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> item;
		tree -> insert(item);
	}

	tree -> printInorder();

	cout << "Enter an item you want to delete " << endl;
	cin >> item;
	tree -> deleteBT(item);	
	tree -> printInorder();
}