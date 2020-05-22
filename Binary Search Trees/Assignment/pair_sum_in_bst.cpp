// Pair sum in a BST
// Send Feedback
// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
// Assume BST contains all unique elements.
// Note: In a pair, print the smaller element first.
// Input format:

// Line 1: Elements in the level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Line 2: S

// Output format: Each pair in a different line (pair elements separated by space)

// Sample Input :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 12
// Sample Output
// 2 10
// 5 7

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
unordered_map<int,bool> present;
bool search(BinaryTreeNode<int> *root, int s){
  if(root==NULL)
    return false;
  else if(root->data==s)
    return true;
  //bool a,b;
  else if(s<root->data)
    return search(root->left,s);
  else
    return search(root->right,s);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
  static BinaryTreeNode<int>* rootfix=root;
	if(root==NULL)
      return;
  	else{
      //recursive call
      printNodesSumToS(root->left,s);
  	  printNodesSumToS(root->right,s);
      //small calculation
      int k=s-root->data;
      bool a;
      if(k<root->data&&present[k]==false&&present[root->data]==false){
        present[root->data]=true;
      	present[k]=true;
        a=search(rootfix,k);
        if(a==true){
            cout<<k<<" "<<root->data<<endl;
        }
      }
      else if(k>root->data&&present[k]==false&&present[root->data]==false){
        present[root->data]=true;
      	present[k]=true;
        a=search(rootfix,k);
        if(a==true){
        	cout<<root->data<<" "<<k<<endl;
        }
      }
     	 	
    }
  
  
  	
  	
}
