// Count nodes
// Send Feedback
// Given a tree and an integer x, find and return the number of Nodes which are greater than x.
// Input format :
// Line 1 : Integer x
// Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output Format :
// Count of nodes greater than x
// Sample Input 1 :
// 35
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1 :
// 3
// Sample Input 2 :
// 10
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 2:
// 5

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

int nodesGreaterThanX(TreeNode<int> *root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  if(root==NULL)
    return 0;
  int count;
  if(root->data>x)
    count=1;
  else
    count=0;
  for(int i=0;i<root->children.size();i++){
    count+=nodesGreaterThanX(root->children[i],x);
  }
  return count;

}

