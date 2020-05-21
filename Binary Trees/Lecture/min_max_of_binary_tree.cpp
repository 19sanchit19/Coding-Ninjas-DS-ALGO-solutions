// Min and Max of Binary Tree
// Send Feedback
// Given a binary tree, find and return the min and max data value of given binary tree.
// Return the output as an object of PairAns class, which is already created.
// Input format :
// Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Output Format :
// Max and min (separated by space)
// Sample Input :
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// Sample Output :
// 14 1

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
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
***************/

PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  //base case
  if(root==NULL){
	PairAns p;
    p.min=0;
    p.max=0;
    return p;
  }
  //hypothesis
  PairAns leftAns=minMax(root->left);
  PairAns rightAns=minMax(root->right);
  //induction step
  PairAns p;
  p.min=root->data;
  p.max=root->data;
  //if(leftAns!=0&&rightAns!=0){
  	//p.min=min(leftAns.min,min(p.min,rightAns.min));
  	p.max=max(leftAns.max,max(p.max,rightAns.max));
  //}
  /*if(leftAns==0){
    if(rightAns!=0){
    p.min=min(p.min,rightAns.min);
    p.max=max(p.max,rightAns.max);
    }
  }
  if(rightAns==0){
    if(leftAns!=0){
    p.min=min(p.min,leftAns.min);
    p.max=max(p.max,leftAns.max);
    }
  }*/
  if(leftAns.min!=0&&rightAns.min!=0)
    p.min=min(leftAns.min,min(rightAns.min,p.min));
  if(leftAns.min==0&&rightAns.min!=0)
    p.min=min(p.min,rightAns.min);
  if(leftAns.min!=0&&rightAns.min==0)
    p.min=min(p.min,leftAns.min);
    
    
  return p;

}
