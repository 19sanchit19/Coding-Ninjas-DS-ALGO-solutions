// Preorder Binary Tree
// Send Feedback
// Given a binary tree, print the preorder traversal of given tree.
// Pre-order traversal is: Root LeftChild RightChild
// Input format :
// Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Output Format :
// Pre-order traversal, elements separated by space
// Sample Input :
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// Sample Output :
// 8 3 1 6 4 7 10 14 13

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
#include<vector>
vector<int> preorder(BinaryTreeNode<int>* root){
  if(root==NULL){
    vector<int> ans;
    return ans;		//check this
  }
  vector<int> ans;
  ans.push_back(root->data);
  vector<int> ans1=preorder(root->left);
  vector<int> ans2=preorder(root->right);
  for(int i=0;i<ans1.size();i++){
    ans.push_back(ans1[i]);
  }
  for(int i=0;i<ans2.size();i++){
    ans.push_back(ans2[i]);
  }
  return ans;
  
}
void preOrder(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
	vector<int> ans;
  	vector<int> final_ans=preorder(root);
  	for(int i=0;i<final_ans.size();i++)
      cout<<final_ans[i]<<" ";
}
