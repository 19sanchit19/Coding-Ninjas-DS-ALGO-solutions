// Eliminate duplicates from LL
// Send Feedback
// Given a sorted linked list (elements are sorted in ascending order). Eliminate duplicates from the given LL, such that output LL contains only unique elements.
// You don't need to print the elements, just remove duplicates and return the head of updated LL.
// Input format : Linked list elements (separated by space and terminated by -1)

// Sample Input 1 :
// 1 2 3 3 3 4 4 5 5 5 7 -1
// Sample Output 1 :
// 1 2 3 4 5 7

//solution

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/


////START AFRESH

node* eliminate_duplicate(node* head)
{
    //write your code here
  node* temp1=head;
  node* temp2=head->next;
  //base case
  if(temp2==NULL)
    return head;
  //small calculation
  if(temp1->data==temp2->data){
    temp1->next=temp2->next;
    delete temp2;
    node *p=eliminate_duplicate(head);
    return p;
  }
  //recursive call
  eliminate_duplicate(head->next);
  return head;
  
}
