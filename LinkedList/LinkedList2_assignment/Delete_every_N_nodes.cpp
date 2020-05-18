// Delete every N nodes
// Send Feedback
// Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.
// Input format :

// Line 1 : Linked list elements (separated by space and terminated by -1)

// Line 2 : M

// Line 3 : N

// Sample Input 1 :
// 1 2 3 4 5 6 7 8 -1
// 2
// 2
// Sample Output 1 :
// 1 2 5 6
// Sample Input 2 :
// 1 2 3 4 5 6 7 8 -1
// 2
// 3
// Sample Output 2 :
// 1 2 6 7

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

node* skipMdeleteN(node  *head, int M, int N)
{
  if(M==0)
    return NULL;
    // Write your code here
  node* temp=head;//temporary variable pointing to current element
  while(temp!=NULL&&temp->next!=NULL)
  {
    for(int i=0;i<M-1;i++)
    {
      if(temp!=NULL)
      	temp=temp->next;
      else
        break;
    }
    for(int j=0;j<N;j++)
    {
      if(temp!=NULL&&temp->next!=NULL)
      {
      	node* b=temp->next;
      	temp->next=b->next;
      	delete b;
      }
      else
        break;
    }
    if(temp!=NULL)
    	temp=temp->next;
    else
      break;
  }
  return head;

}
