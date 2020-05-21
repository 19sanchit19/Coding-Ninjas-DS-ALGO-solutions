// Level order traversal
// Send Feedback
// Given a binary tree, print the level order traversal. Make sure each level start in new line.
// Input format :

// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

// Output Format :

// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 5 
// 6 10 
// 2 3 
// 9

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
#include<queue>
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root==NULL)
    return;
  queue<BinaryTreeNode<int>*> pendinglevel;
  pendinglevel.push(root);
  pendinglevel.push(NULL);
  while(pendinglevel.size()!=0){
    BinaryTreeNode<int> *front=pendinglevel.front();
    pendinglevel.pop();
    if(front!=NULL){
    	cout<<front->data<<" ";
      if(front->left!=NULL)
    	pendinglevel.push(front->left);
      if(front->right!=NULL)
      	pendinglevel.push(front->right);
    }
    else{
      	cout<<endl;
      if(pendinglevel.size()!=0)
      	pendinglevel.push(NULL);
      else
        break;
    }
  }
}
