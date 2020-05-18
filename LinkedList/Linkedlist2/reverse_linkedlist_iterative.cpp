// Code: Reverse LL (Iterative)
// Send Feedback
// Given a linked list, reverse it iteratively.
// You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
// Input format : Linked list elements (separated by space and terminated by -1)`

// Sample Input 1 :
// 1 2 3 4 5 -1
// Sample Output 1 :
// 5 4 3 2 1

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
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here#
  if(head==NULL||head->next==NULL)
    return head;
  node* a=head;
  node* b=head->next;
  node* temp=b->next;
  b->next=a;
  a->next=NULL;
  a=b;
  b=temp;
  while(b!=NULL)
  {
    temp=b->next;
    b->next=a;
    a=b;
    b=temp;
  }
  return a;
}

