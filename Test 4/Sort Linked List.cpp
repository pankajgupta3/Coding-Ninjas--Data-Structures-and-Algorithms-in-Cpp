/* Code: Sort Linked List
Given a Linked List, which has nodes in alternating ascending and descending orders. Sort the list efficiently and space complexity should be O(1).
You just need to return the head of sorted linked list, don't print the elements.
Input format :
Line 1 : Linked list elements of length L (separated by space and terminated by -1)
Line 2 : Integer n
Output format :
Updated list elements (separated by space)
Sample Input 1 :
10 40 53 30 67 12 89 -1
Sample Output 1 :
10 12 30 40 53 67 89
*/

// Solution:
Node<int>* reverseLinkedList(Node<int>* head){
    // Write your code here
    Node<int>* curr = head;
    Node<int>* prev = NULL;
    while(curr != NULL){
        Node<int>* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
Node<int>* mergeTwoSortedLinkedLists(Node<int>* head1, Node<int>* head2){
    //Write your code here()
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node<int>* newHead = NULL;
    Node<int>* newTail = NULL;
    if(head1 -> data < head2->data){
        newHead = head1;
        newTail = head1;
        head1 = head1 -> next;
    }
    else{
        newHead = head2;
        newTail = head2;
        head2 = head2 -> next;
    }
    while(head1 != NULL and head2 != NULL){
        if(head1 -> data < head2 -> data){
            newTail -> next = head1;
            newTail = newTail -> next;
            head1 = head1 -> next;
        }
        else{
            newTail -> next = head2;
            newTail = newTail -> next;
            head2 = head2 -> next;
        }
    }
    if(head1 != NULL){
        newTail -> next = head1;
    }
    if(head2 != NULL){
        newTail -> next = head2;
    }
    return newHead;
}
Node<int>* sort(Node<int>* head){
    if(head == NULL){
        return head;
    }
    if(head -> next == NULL){
        return head;
    }
    Node<int>* ascHead = NULL;
    Node<int>* ascTail = NULL;
    Node<int>* descHead = NULL;
    Node<int>* descTail = NULL;
    
    
    Node<int>* temp = head;
	
    ascHead = ascTail = temp;
    temp = temp -> next;
    descHead = descTail = temp;
    temp = temp ->next;
    
    while(temp != NULL){
        ascTail -> next = temp;
        ascTail = ascTail -> next;
        temp = temp -> next;
        if(temp != NULL){
            descTail -> next = temp;
            descTail = descTail -> next;
            temp = temp -> next;
        }
    }
    ascTail -> next = NULL;
    descTail -> next = NULL;
    descHead = reverseLinkedList(descHead);
    Node<int>* ansHead = mergeTwoSortedLinkedLists(ascHead, descHead);
    return ansHead;
}

// Main Code:
/*
#include<iostream>
using namespace std;
template<typename T>
class Node{
  public :
  T data;
  Node<T>* next;
  Node(T data){
    this->data = data;
  }
};

Node<int>* takeinput(){
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newNode = new Node<int>(data);
        if(head==NULL)                  {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node<int> *head)
{
    Node<int>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
#include "solution.h"
int main()
{
    Node<int>* head=takeinput();
    head= sort(head);
    print(head);
    return 0;
}

*/