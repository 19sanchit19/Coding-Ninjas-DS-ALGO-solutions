// Code: BST to Sorted LL
// Send Feedback
// Given a BST, convert it into a sorted linked list. Return the head of LL.
// Input format :
// Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Output Format :
// Linked list elements (separated by space)
// Sample Input :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// Sample Output :
// 2 5 6 7 8 10

//solution

// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  if(root==NULL){
    return NULL;
  }
  Node<int>* ans1=constructBST(root->left);
  Node<int>* ans2=constructBST(root->right);
  Node<int>* a=new Node<int>(root->data);
  //cout<<a->data<<endl;
  Node<int>* temp=ans1;
  if(temp!=NULL)
  {
  	while(temp->next!=NULL){
    	temp=temp->next;
  	}
  	temp->next=a;
  	a->next=ans2;
  	return ans1;
  }
  else{
    a->next=ans2;
    return a;
  }
  //return a;
    
}