// Path Sum Root to Leaf
// Send Feedback
// Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
// Input format :

// Line 1 : Elements in level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Line 2 : k

// Output format : Print each path in new line, elements separated by space

// Sample Input 1 :
// 5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
// 13
// Sample Output 1 :
// 5 6 2
// 5 7 1

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
unordered_map<BinaryTreeNode<int>*,int> sum;
unordered_map<BinaryTreeNode<int>*,bool> visited;
bool isSumOk(BinaryTreeNode<int>* root,int k){
  if(root==NULL)
    return false;
  else if(root->left==NULL&&root->right==NULL){
    if(root->data==k){
      sum[root]++;
      return true;
    }
    else
      return false;
  }
  else{
    bool leftans=isSumOk(root->left,k-root->data);
    bool rightans=isSumOk(root->right,k-root->data);
    if(leftans==true)
      sum[root]++;
    if(rightans==true)
      sum[root]++;
    return leftans||rightans;
  }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
  	static bool ans=isSumOk(root,k);
  	/*for(auto itr=sum.begin();itr!=sum.end();itr++)
      cout<<itr->first->data<<" "<<itr->second<<endl;*/
  	//cout<<i_cnt<<endl;
  	static BinaryTreeNode<int>* rootfix=root;
	if(root==NULL)
      return;
  	else if(root->left!=NULL||root->right!=NULL){  		
      	if(sum[root]>0){
          cout<<root->data<<" ";
          sum[root]--;
          //visited[root]=true;
        }
      	rootToLeafPathsSumToK(root->left,k);
      	rootToLeafPathsSumToK(root->right,k);
    }
  	else{
      if(sum[root]>0){
        cout<<root->data<<endl;
        sum[root]--;
      	//visited[root]=true;
        //visted[rootfix]=false;
        rootToLeafPathsSumToK(rootfix,k);
      }
    }
}
