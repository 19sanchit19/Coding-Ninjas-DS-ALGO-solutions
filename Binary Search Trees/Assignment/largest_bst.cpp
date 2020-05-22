// Largest BST
// Send Feedback
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
// Return the height of largest BST.
// Input format :

// Line 1 : Elements in level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 1:
// 2

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
#include<limits.h>
bool isBST(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
  if(root==NULL)
    return true;
  if(root->data<min||root->data>max)
    return false;
  bool isLeftOk=isBST(root->left,min,root->data);
  bool isRightOk=isBST(root->right,root->data,max);
  return isLeftOk&&isRightOk;

}
int height(BinaryTreeNode<int>* root){
  if(root==NULL)
    return 0;
  return max(height(root->left),height(root->right))+1;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root==NULL)
    return 0;
  else{
    //static vector<int> ans;
    if(isBST(root))
      return height(root);
    else{
      int a,b;
      if(isBST(root->left))
        a=height(root->left);
      if(isBST(root->right))
        b=height(root->right);
      return max(a,b);
    }
  }
  

}
