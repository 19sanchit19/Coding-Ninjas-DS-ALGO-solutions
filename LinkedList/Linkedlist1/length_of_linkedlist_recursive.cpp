// Length of LL (recursive)
// Send Feedback
// Given a linked list, find and return the length of input LL recursively.
// Input format :
// Linked list elements (separated by space and terminated by -1)
// Output format :
// Length of LL
// Sample Input :
// 3 4 5 2 6 1 9 -1
// Sample Output :
// 7

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

int length(Node *head) 
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  //base case
  if(head==NULL)
    return 0;
  int a=length(head->next);
    return a+1;
}


