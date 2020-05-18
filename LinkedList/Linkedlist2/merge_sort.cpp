// Code: Merge Sort
// Send Feedback
// Sort a given linked list using Merge Sort.
// You don't need to print the elements, just sort the elements and return the head of updated LL.
// Input format :
// Linked list elements (separated by space and terminated by -1)
// Output format :
// Updated LL elements (separated by space)
// Constraints :
// 1 <= Length of LL <= 1000
// Sample Input 1 :
// 1 4 5 2 -1
// Sample Output 1 :
// 1 2 4 5

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
node* midpoint_linkedlist(node *head)
{
    // Write your code here
  node* slow=head;
  node* fast=head->next;
  while(fast!=NULL&&fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
	return slow;
}
node* mergeTwoLLs(node *head1, node *head2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  node* fhead=NULL;
  node* ftail=NULL;
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
node* mergeSort(node *head) 
{
    //write your code here
  //we will handle this problem recursively
  //base case 
  if(head->next==NULL)
    return head;
  //dividing the linked list into two halves about the midpoint
  node* p1=midpoint_linkedlist(head);
  node* a1=p1->next;
  p1->next=NULL;
  //recursive call
  node* x=mergeSort(head);
  node* y=mergeSort(a1);
  //our part--small calculation
  node* z=mergeTwoLLs(x,y);
  return z;
}
