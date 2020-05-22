// Find Path in BST
// Send Feedback
// Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.
// Assume that BST contains all unique elements.
// Input Format :
// Line 1 : Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Line 2 : Integer k
// Output Format :
// Path from node k to root
// Sample Input :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 2
// Sample Output :
// 2
// 5
// 8

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
pair<vector<int>*,bool> FindPath(BinaryTreeNode<int>* root,int data){
  //base case
  if(root==NULL){
    pair<vector<int>*,bool> p;
    vector<int>* v=new vector<int>;
    bool a=false;
    p.first=v;
    p.second=a;
    return p;
  }
  //base case 2=> leaf node
  else if(root->left==NULL&&root->right==NULL&&root->data!=data){
    pair<vector<int>*,bool> p;
    vector<int>* v=new vector<int>;
    bool a=false;
    p.first=v;
    p.second=a;
    return p;
  }
  else if(root->left==NULL&&root->right==NULL&&root->data==data){
    pair<vector<int>*,bool> p;
    vector<int>* v=new vector<int>;
    bool a=true;
    v->push_back(root->data);
    p.first=v;
    p.second=a;
    return p;
  }
  //recursive call
  else if(root->data==data){
    pair<vector<int>*,bool> p;
    vector<int>* v=new vector<int>;
    bool a=true;
    v->push_back(root->data);
    p.first=v;
    p.second=a;
    return p;
  }
  pair<vector<int>*,bool> p1=FindPath(root->left,data);
  if(p1.second==true){
    vector<int>* ans=p1.first;
    ans->push_back(root->data);
    return p1;
  }
  else{
    pair<vector<int>*,bool> p2=FindPath(root->right,data);
    if(p2.second==true){
      vector<int>* ans=p2.first;
      ans->push_back(root->data);
      return p2;
    }
    else
      return p2;
  }
  //small calculation
}
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	pair<vector<int>*,bool> b=FindPath(root,data);
  	return b.first;
}
