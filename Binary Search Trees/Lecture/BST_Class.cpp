// Code: BST Class
// Send Feedback
// Implement the BST class which includes following functions -
// 1. search
// Given an element, find if that is present in BSt or not. Return true or false.
// 2. insert -
// Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
// 3. delete -
// Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
// 4. printTree (recursive) -
// Print the BST in ithe following format -
// For printing a node with data N, you need to follow the exact format -
// N:L:x,R:y
// wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
// There is no space in between.
// You need to print all nodes in the recursive format in different lines.
// Note : main function is given for your reference which we are using internally to test the class.


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
