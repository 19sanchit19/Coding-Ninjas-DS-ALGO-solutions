// Code: Merge Two Sorted LL
// Send Feedback
// Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
// Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.
// Input format :
// Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
// Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)
// Output format :
// Merged list elements (separated by space)
// Constraints :
// 1 <= n, m <= 10^4
// Sample Input :
//  2 5 8 12 -1
//  3 6 9 -1
// Sample Output :
//  2 3 5 6 8 9 12

//solution

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* mergeTwoLLs(Node *head1, Node *head2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  Node* fhead=NULL;
  Node* ftail=NULL;
  if(head1->data<=head2->data)
  {
    fhead=head1;
    ftail=head1;
    head1=head1->next;
  }
  else
  {
    fhead=head2;
    ftail=head2;
    head2=head2->next;
  }
  while(head1!=NULL&&head2!=NULL)
  {
    if(head1->data<=head2->data)
    {
      ftail->next=head1;
      ftail=ftail->next;
      head1=head1->next;
    }
    else
    {
      ftail->next=head2;
      ftail=ftail->next;
      head2=head2->next;
    }
  }
  if(head1==NULL)
  {
    ftail->next=head2;
  }
  else
  {
    ftail->next=head1;
  }
  return fhead;
} 