/* Code: Insertion Sort(Iteratively) LinkedList
Sort a given linked list using Insertion Sort (iteratively).
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
*/

// Solution:
node* insertion_sort_LinkedList_itr(node* head)
{
    //write your code here
    if(head == NULL){
        return NULL;
    }
    node *tail = head;
    node *curr, *iter;
    while(tail -> next != NULL){
        if(tail -> data <= tail -> next -> data){
            tail = tail -> next;
            continue;
        }
        curr = tail -> next;
        tail -> next = curr -> next;
        if(curr -> data < head -> data){
            curr -> next = head;
            head = curr;
            continue;
        }
        iter = head;
        while(iter != tail){
            if(curr -> data < iter -> next -> data){
                curr -> next = iter -> next;
                iter -> next = curr;
                break;
            }
            iter = iter -> next;
        }
    }
    return head;
}

// Main Code:
/*
//insertion sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head=insertion_sort_LinkedList_itr(head);
    print(head);
}
*/