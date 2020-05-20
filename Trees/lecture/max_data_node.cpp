// Code : Max data node
// Send Feedback
// Given a generic tree, find and return the node with maximum data. You need to return the complete node which is having maximum data.
// Return null if tree is empty.
// Input format :
// Elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output Format :
// Node with largest data
// Sample Input :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output :
// 50

//solution

// Following is the given Tree node structure.
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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  if(root==NULL)
    return 0;
  int max=root->data;
  TreeNode<int>* maxNode=root;
  for(int i=0;i<root->children.size();i++){
    TreeNode<int>* k=maxDataNode(root->children[i]);
    if(k->data>=max)
    {
      max=k->data;
      maxNode=k;
    }
    else
      continue;
  }
	return maxNode;
}

