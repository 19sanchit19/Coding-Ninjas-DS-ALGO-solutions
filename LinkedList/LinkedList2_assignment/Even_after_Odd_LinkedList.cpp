// Even after Odd LinkedList
// Send Feedback
// Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
// Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.
// Input format:
// Linked list elements (separated by space and terminated by -1)
// Output format:
// Print the elements of updated Linked list. 
// Sample Input 1 :
// 1 4 5 2 -1
// Sample Output 1 :
// 1 5 4 2 
// Sample Input 2 :
// 1 11 3 6 8 0 9 -1
// Sample Output 2 :
// 1 11 3 9 6 8 0

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

node* arrange_LinkedList(node* head)
{
    //write your code here
  //we will handle this using recursion
  //base case
  if(head==NULL||head->next==NULL)
    return head;
  //recursive call
  node* p=arrange_LinkedList(head->next);
  
  
  //our part
  if(head->data%2!=0)
  {
    head->next=p;
    return head;
  }
  else
  {
    node* temp=p;
    if(temp->next==NULL)
    {
      if(temp->data%2!=0)
      {
     	temp->next=head;
     	head->next=NULL;
      }
      else
      {
        head->next=temp;
        return head;
      }
    }
    else
    {
    	if(temp->data%2!=0)
    	{
    		while(temp->next->data%2!=0)
    		{
      			temp=temp->next;
    		}
    		head->next=temp->next;
    		temp->next=head;
    	}
    	else
    	{
      		head->next=temp;
      		return head;
    	}
    }
   return p;   
  }
}
