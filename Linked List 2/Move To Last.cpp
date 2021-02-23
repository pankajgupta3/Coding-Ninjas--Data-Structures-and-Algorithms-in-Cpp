/*
Move To Last
Given a linked list and a key in it, the task is to move all occurrences of given key to end of linked list, keeping order of all other elements same.
Return the updated head of LL.
Input Format :
Line 1 : Elements of the linked list ending with -1 (-1 not included)
Line 2 : Key n, Element which has to shifted
Output Format :
Updated linked list
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 2 2 3 4 5 -1
2
Sample Output 1:
1 3 4 5 2 2 
Sample Input 2:
1 1 2 3 4 -1
1
Sample Output 2:
2 3 4 1 1
*/

// Solution:
Node<int>* func(Node<int> *head,int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	
    Node<int>* temp = head; 
    Node<int>* keyNode = head; 
    while(temp != NULL){ 
        if(temp != keyNode && temp -> data != n){ 
            keyNode -> data = temp -> data; 
            temp -> data = n; 
            keyNode = keyNode -> next; 
        } 
        if(keyNode -> data != n){
            keyNode = keyNode -> next; 
        } 
        temp = temp -> next; 
    }
    return head;
}

// Main Code:
/*
#include <iostream>
using namespace std;
template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
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
void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node<int>* head1 = takeLLInput();
	int n;
	cin>>n;
	printLL(func(head1,n));	
	delete head1;
	
}
*/