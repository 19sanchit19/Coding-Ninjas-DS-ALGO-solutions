// AppendLastNToFirst
// Send Feedback
// Given a linked list and an integer n, append the last n elements of the LL to front.
// Indexing starts from 0. You don't need to print the elements, just update the elements and return the head of updated LL.
// Assume given n will be smaller than length of LL.
// Input format :

// Line 1 : Linked list elements (separated by space and terminated by -1)`

// Sample Input 1 :
// 1 2 3 4 5 -1
// 3
// Sample Output 1 :
// 3 4 5 1 2

//solution

//head is the head of the linked list and n is  how many element you want to append from the last to the front
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
***********/

/*int length(node *head) 
{
  //base case
  if(head==NULL)
    return 0;
  int a=length(head->next);
    return a+1;
}*/


int length(node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  if(head!=NULL)
  {
    	node *temp=head;
  		int count=0;
  		while(temp->next!=NULL){
      	temp=temp->next;
      	count++;
    	}
  	return count+1;
  }
  else
    return 0;
}




node* append_LinkedList(node* head,int n)
{
    //write your code here
  node*temp=head;
  int l=length(head);
  //reaching required node
  for(int i=0;i<l-n-1;i++){
    temp=temp->next;
  }
  node *temp2=temp->next;
  node *temp3=temp;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=head;
  temp3->next=NULL;
  return temp2;
}
