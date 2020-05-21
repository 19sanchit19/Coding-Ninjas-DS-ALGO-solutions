// Level wise linkedlist
// Send Feedback
// Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
// Input format :

// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

// Output format : Each level linked list is printed in new line (elements separated by space).

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 5 
// 6 10 
// 2 3 
// 9

//solution

// Following is the Node and Binary Tree node structure

/**************
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
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
#include<queue>

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<node<int>*> ans;	
  	if(root==NULL)
      return ans;
      //write edge case
    queue<BinaryTreeNode<int>*> pending;
  	pending.push(root);
  	pending.push(NULL);
  	//node<int> *llroot= new node <int>(root->data);
  	//ans.push_back(llroot);
  	int i=0;
  	int j=0;
  	node<int> *tail;
  	while(pending.size()!=0){
      BinaryTreeNode<int> *front=pending.front();
      pending.pop();
      node<int>* llnode;
      node<int>* llroot;
      if(front!=NULL&&i==0){
        if(front->left!=NULL)
          pending.push(front->left);
        if(front->right!=NULL)
          pending.push(front->right);
        
        llroot= new node<int>(front->data);
        tail=llroot;
        ans.push_back(llroot);
        j++;
        i=1;
      }
      else if(front!=NULL&&i==1){
        if(front->left!=NULL)
          pending.push(front->left);
        if(front->right!=NULL)
          pending.push(front->right);
        llnode= new node<int>(front->data);
        tail->next=llnode;
        //USE TAIL
        tail=llnode;
        i=1;
      }
      else if(front==NULL&&i==1){		//CHECK
        tail->next=NULL;
        tail=NULL;//Check if neccessary
        if(pending.size()!=0)
          pending.push(NULL);
        else
          break;
        i=0;
      }
      else{				//CHECK
        break;
      }
     
    }
  return ans;
}
