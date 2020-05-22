// LCA of Binary Tree
// Send Feedback
// Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
// If out of 2 nodes only one node is present, return that node.
// If both are not present, return -1.
// Input format :
// Line 1 :  Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Line 2 : Two integers, Node 1 and Node 2 (separated by space)
// Output Format :
// LCA
// Constraints :
// 1 <= N <= 1000
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 10
// Sample Output 1:
// 10
// Sample Input 2:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 6
// Sample Output 2:
// 5
// Sample Input 3:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 12 78
// Sample Output 3:
// -1

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
BinaryTreeNode<int>* ispresent(BinaryTreeNode<int>* root, int val){
  if(root==NULL)
    return NULL;
  if(root->data==val)
    return root;
  BinaryTreeNode<int>* ans1=ispresent(root->left,val);
  if(ans1!=NULL)
    return ans1;
  else{
    return ispresent(root->right,val);
  }
}
int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
	if(root==NULL)
      return -1;
  	BinaryTreeNode<int>* ans1=ispresent(root,val1);
    BinaryTreeNode<int>* ans2=ispresent(root,val2);
  	if(ans1==NULL||ans2==NULL){
      if(ans1==NULL&&ans2==NULL)
        return -1;
      else if(ans1!=NULL&&ans2==NULL)
        return ans1->data;
      else
        return ans2->data;
    }
  else{
    if(ispresent(ans2,val1)!=NULL)
      return ans2->data;
    else if(ispresent(ans1,val2)!=NULL)
      return ans1->data;
    else{
      //both in left subtree
      if(ispresent(root->left,val1)!=NULL&&ispresent(root->left,val2)!=NULL)
        return lcaBinaryTree(root->left,val1,val2);
      
      //both in right subtree
      else if(ispresent(root->right,val1)!=NULL&&ispresent(root->right,val2)!=NULL)
        return lcaBinaryTree(root->right,val1,val2);
      
      //each one on diff sides of root
      else	
      	return root->data;
    }
  }
}
