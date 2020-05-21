// ZigZag tree
// Send Feedback
// Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
// Input format :

// Elements in level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Output Format :

// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 5
// 10 6
// 2 3
// 9

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
#include<queue>
#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)
      return;
  	queue<BinaryTreeNode<int>*> pending;
  	queue<BinaryTreeNode<int>*> printq;
  	stack<BinaryTreeNode<int>*> prints;
  	pending.push(root);
  	pending.push(NULL);
  	int i=0;
  	while(pending.size()!=0){
      BinaryTreeNode<int> *front=pending.front();
      pending.pop();
      if(front!=NULL){
        if(front->left!=NULL)
          pending.push(front->left);
        if(front->right!=NULL)
          pending.push(front->right);
        if(i%2==0){			//ENTER QUEUE
 			printq.push(front);
        }
        else{				//ENTER STACK
         	prints.push(front);
        }
          
      }
      else{
        if(i%2==0){
          //empty queue
          while(printq.size()!=0){
            cout<<printq.front()->data<<" ";
            printq.pop();
          }
        }
        else{
          //emptystack
          while(prints.size()!=0){
            cout<<prints.top()->data<<" ";
            prints.pop();
          }
        }
        if(pending.size()!=0)
          pending.push(NULL);
        else
          break;
        cout<<endl;
        i++;
      }
    }
}
