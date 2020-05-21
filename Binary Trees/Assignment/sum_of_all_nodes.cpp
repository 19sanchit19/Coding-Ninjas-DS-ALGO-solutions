// Sum of all nodes
// Send Feedback
// Given a binary tree, find and return the sum of all nodes.
// Input format :

// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 35

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

int sumOfAllNodes(BinaryTreeNode<int>* root) {
    // Write your code here
  if(root==NULL)
    return 0;
  int sum=root->data;
  sum+=sumOfAllNodes(root->left)+sumOfAllNodes(root->right);
  return sum;
  

}
