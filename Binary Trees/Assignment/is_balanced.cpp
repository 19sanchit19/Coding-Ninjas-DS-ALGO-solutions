// is Balanced
// Send Feedback
// Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
// Input format :

// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

// Sample Input 1 :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 1 :
// false
// Sample Input 2 :
// 1 2 3 -1 -1 -1 -1
// Sample Output 2 :
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
class myclasspair{
  public:
  int height;
  bool isbalanced;
};
int abs(int x){
  if(x>=0)
    return x;
  else
    return -1*x;
}
myclasspair isBalanced1(BinaryTreeNode<int>* root){
  //base case
  if(root==NULL){
    myclasspair empty;
    empty.height=0;
    empty.isbalanced=true;
    return empty;
  }
  myclasspair a=isBalanced1(root->left);
  myclasspair b=isBalanced1(root->right);
  myclasspair ans;
  if(a.isbalanced&&b.isbalanced==true){
    if(abs(a.height-b.height)<=1){
      ans.isbalanced=true;
    }
    else{
      ans.isbalanced=false;
    }
      
  }
  else{
    ans.isbalanced=false;
  }
  ans.height=max(a.height,b.height)+1;
    
  return ans;
}
bool isBalanced(BinaryTreeNode<int> *root){
    // Write your code here
  myclasspair originalans=isBalanced1(root);
  bool ans=originalans.isbalanced;
  return ans;

}
