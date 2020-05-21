// Construct Tree from Postorder and Inorder
// Send Feedback
// Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
// Note: Assume binary tree contains only unique elements.
// Input format :

// Line 1 : n (Total number of nodes in binary tree)

// Line 2 : Post order traversal

// Line 3 : Inorder Traversal

// Output Format :

// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 8
// 8 4 5 2 6 7 3 1
// 4 8 2 5 1 6 3 7
// Sample Output :
// 1 
// 2 3 
// 4 5 6 7 
// 8

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

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) 
{
    // Write your code here
	int rootdata = *(postorder+postLength-1);
  	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
  	if(postLength==0)
      return 0;
  	int i=0;
  	for(;i<inLength;i++){
      if(*(inorder+i)==rootdata)
        break;
    }
  	int *leftpostorder=postorder;
  	int leftlength=i;
  	int *leftinorder=inorder;
  	BinaryTreeNode<int> *leftnode=getTreeFromPostorderAndInorder(leftpostorder,leftlength,leftinorder,leftlength);
  	int *rightpostorder=leftpostorder+leftlength;
  	int rightlength=inLength-leftlength-1;
  	int *rightinorder=inorder+leftlength+1;
 	BinaryTreeNode<int> *rightnode=getTreeFromPostorderAndInorder(rightpostorder,rightlength,rightinorder,rightlength);
  	root->left=leftnode;
  	root->right=rightnode;
  	return root;
}
