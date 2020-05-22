// Replace with Sum of greater nodes
// Send Feedback
// Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. You need to include the current node's data also.
// That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
// You don't need to return or print, just change the data of each node.
// Input format :

// Line 1 : Elements in level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Output format : Elements are printed in level order wise, every level in new line

// Sample Input 1 :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// Sample Output 1 :
// 18 
// 36 10 
// 38 31 
// 25 

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
#include<unordered_map>
vector<int> inorder(BinaryTreeNode<int>* root){
  if(root==NULL){
    vector<int> v;
    return v;
  }
  else{
    vector<int> v1=inorder(root->left);
    v1.push_back(root->data);
    vector<int> v2=inorder(root->right);
    for(int i=0;i<v2.size();i++){
      v1.push_back(v2[i]);
    }
    return v1;
  }
}
BinaryTreeNode<int>* search(BinaryTreeNode<int>* root,int data){
  if(root==NULL){
    return NULL;
  }
  else{
    if(root->data==data)
      return root;
    else if(data<root->data)
      return search(root->left,data);
    else
      return search(root->right,data);    
  }
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<int> v=inorder(root);
  	int sum=0;
  	unordered_map<int,BinaryTreeNode<int>*> node;
  	for(int i=0;i<v.size();i++){
      sum+=v[i];
      node[v[i]]=search(root,v[i]);
    }
  	for(int i=0;i<v.size();i++){
      int a=v[i];
      int b=sum;
      BinaryTreeNode<int>* c=node[a];
      c->data=b;
      sum-=v[i];
    }
  	
}
