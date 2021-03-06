// Code : Find a node
// Send Feedback
// Given a Binary Tree and an integer x, check if node with data x is present in the input binary tree or not. Return true or false.
// Input format :
// Line 1 : Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Line 2 : Integer x
// Output Format :
// true or false
// Sample Input :
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// 7
// Sample Output :
// true

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

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  if(root==NULL){
    return false;
  }
  if(root->data==x){
    return true;
  }
  return isNodePresent(root->left,x) || isNodePresent(root->right,x);

}
