// Check if a Binary Tree is BST
// Send Feedback
// Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
// Duplicate elements should be in right subtree.
// Input format :
// Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
// Output format :
// true or false
// Constraints :
// 1 <= N <= 10^5
// Sample Input 1 :
// 3 1 5 -1 2 -1 -1 -1 -1
// Sample Output 1 :
// true
// Sample Input 2 :
// 5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
// Sample Output 2 :
// false

//solution

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