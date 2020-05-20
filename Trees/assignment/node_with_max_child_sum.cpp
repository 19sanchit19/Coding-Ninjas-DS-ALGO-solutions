// Node with maximum child sum
// Send Feedback
// Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
// Input format :
// Line 1 : Elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output format :
// Node with maximum sum.
// Sample Input 1 :
// 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
// Sample Output 1 :
// 1

//solution

// Following is the given Tree node structure
/**************

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
***************/

void add_max(TreeNode<int> *root){
  int max=root->data;
  for(int i=0;i<root->children.size();i++){
    max+=root->children[i]->data;
  }
  TreeNode<int>* maxnode=new TreeNode<int>(max);
  root->children.push_back(maxnode);
  for(int i=0;i<root->children.size()-1;i++){
    add_max(root->children[i]);
  }
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically..
     */
  if(root==NULL){
    return 0;
  }
  static TreeNode<int> *rootfix=root;
  if(root==rootfix){
    add_max(root);
  }
  int k=root->children.size()-1;
  TreeNode<int> *maxans=root;
  int max=root->children[k]->data;
  for(int i=0;i<k;i++){
    TreeNode<int>* ans=maxSumNode(root->children[i]);
    int j=ans->children.size()-1;
    if(ans->children[j]->data>max){
      max=ans->children[j]->data;
      maxans=ans;
    }
  }
	return maxans;
}

