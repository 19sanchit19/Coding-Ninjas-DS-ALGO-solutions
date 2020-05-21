// Code: Construct Tree from Preorder and Inorder
// Send Feedback
// Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
// Note: Assume binary tree contains only unique elements.
// Input format :

// Line 1 : n (Total number of nodes in binary tree)

// Line 2 : Pre order traversal

// Line 3 : Inorder Traversal

// Output Format :

// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 12
// 1 2 3 4 15 5 6 7 8 10 9 12
// 4 15 3 2 5 1 6 10 8 7 9 12
// Sample Output :
// 1 
// 2 6 
// 3 5 7 
// 4 8 9 
// 15 10 12

//solution

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{
    // Write your code here
  	int rootdata = *preorder;
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootdata);
  	if(preLength==0)
      return 0;
  	int i=0;
  	int k=inLength;
  	for(i=0;i<k;i++){
      if(*(inorder+i)==rootdata){
        break;
      }
    }
  	int leftlength=i;
  	int *leftpreorder=preorder+1;
  	BinaryTreeNode<int>* leftnode=buildTree(leftpreorder,leftlength,inorder,leftlength);
  	int *rightpreorder=preorder+leftlength+1;
  	int rightlength=preLength-leftlength-1;
  	int *rightinorder=inorder+leftlength+1;
  	BinaryTreeNode<int>* rightnode=buildTree(rightpreorder,rightlength,rightinorder,rightlength);
  	root->left=leftnode;
  	root->right=rightnode;
  	return root;
}
