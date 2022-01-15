#include<iostream>
using namespace std;

int largest = 0;

//stores node of BST
class node{
	public:
		int data;
		node* left;
		node* right;

		node(int d){
			data = d;
			left = right = NULL;
		}
};

//this class holds information about whether the current node is a 
//root of a BST or not and how many nodes are present in this BST.
class parameter{
	public:
		bool isBST;
		int noOfnodes;
		parameter(bool a,int b){
			isBST = a;
			noOfnodes = b;
		}
};

//build the binary tree from the given preorder and inorder traversals
node* buildTree(int* preo,int* ino,int &i,int start,int end){
    if(start>end){
        return NULL;
    }
    
	node* root = new node(preo[i]);

	int index=-1;
	for(int j = start;j <= end;j++){
		if(ino[j]==preo[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = buildTree(preo,ino,i,start,index-1);
	root->right = buildTree(preo,ino,i,index+1,end);
	return root;
}


parameter findLargestBST(node* root){
    //base case
	if(root == NULL){
		parameter p(true,0);
		return p;
	}

	parameter p0(true,1);
	
	parameter pleft = findLargestBST(root->left);
	if(root->left){
		if(root->left->data < root->data ){
			if(pleft.isBST){
				p0.isBST = true;
				p0.noOfnodes += pleft.noOfnodes;
			}
		}
		else{
			p0.isBST = false;
			p0.noOfnodes=0;
			return p0;
		}
	}

	parameter pright = findLargestBST(root->right);
	if(root->right){
		if(root->right->data > root->data ){
			if(pright.isBST){
				p0.isBST = true;
				p0.noOfnodes+= pright.noOfnodes;
			}
		}
		else{
			p0.isBST = false;
			p0.noOfnodes=0;
			return p0;
		}
	}
    

    if(pleft.isBST and pright.isBST and p0.isBST)
	    largest = max(largest,p0.noOfnodes);
	    
	return p0;
}

int main() {
	int n;
	cin>>n;
	//input inorder and preorder srrays
	int preo[n],ino[n];
	for(int i=0;i<n;i++) 
	    cin>>preo[i];
	    
	for(int i=0;i<n;i++) 
	    cin>>ino[i];

	
	//build the unique binary tree
	int i = 0;
	node* root = buildTree(preo,ino,i,0,n-1);
	
	//print the the no. of nodes in the largest BST in this binary tree
	findLargestBST(root);
	cout<<largest;
	return 0;
}