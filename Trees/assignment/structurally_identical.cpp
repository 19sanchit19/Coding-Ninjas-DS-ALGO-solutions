// Structurally identical
// Send Feedback
// Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.
// Input format :
// Line 1 : Tree 1 elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Line 2 : Tree 2 elements in level order form separated by space (as per done in class). Order is - 
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output format :
// true or false
// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// 10 3 20 30 40 2 40 50 0 0 0 0
// Sample Output 1 :
// true
// Sample Input 2 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// 10 3 2 30 40 2 40 50 0 0 0 0
// Sample Output 2:
// false

//solution

// Following is the Tree node structure
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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	if(root1->data==root2->data){
      if(root1->children.size()==root2->children.size()){
        if(root1->children.size()==0)
          return true;
        for(int i=0;i<root1->children.size();i++){
          bool ans=isIdentical(root1->children[i],root2->children[i]);
          return ans;
        }
      }
      else
        return false;
    }
  else
    return false;
}
