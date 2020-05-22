// Pair sum BInary Tree
// Send Feedback
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Assume binary tree contains all unique elements.
// Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
// Input format :
// Line 1 : Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Line 2 : Integer S
// Output Format :
// Each pair in different line (pair elements separated by space)
// Constraints :
// 1 <= N <= 1000
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15
// Sample Output 1:
// 5 10
// 6 9

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
BinaryTreeNode<int>* search(BinaryTreeNode<int>* root,int val){
  if(root==NULL)
    return NULL;
  else{
  	if(root->data==val)
    	return root;
    else{
 		BinaryTreeNode<int>* leftans= search(root->left,val);
      	if(leftans!=NULL)
          return leftans;
      	else{
        	BinaryTreeNode<int>* rightans= search(root->right,val);
              return rightans;
        }
    }
  }
}
void helper(BinaryTreeNode<int> *root,BinaryTreeNode<int>* start,int sum){
  //base case
  if(root==NULL||(root->left==NULL&&root->right==NULL)||start==NULL)
    return;
  BinaryTreeNode<int>* leftans=search(root,sum-(start->data));
  if(leftans!=NULL){
  	cout<<min(leftans->data,start->data)<<" "<<max(leftans->data,start->data)<<endl;
    leftans->data=start->data;
  }
    // BinaryTreeNode<int>* rightans=search(root->right,sum-(start->data));
 // if(rightans!=NULL)
  	//cout<<min(rightans->data,root->data)<<" "<<max(rightans->data,root->data)<<endl;
  helper(root,start->left,sum);
  helper(root,start->right,sum);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
  helper(root,root,sum);
}

//try after completing search function
/*

*/