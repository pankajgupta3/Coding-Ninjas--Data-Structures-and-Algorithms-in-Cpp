/* Code: Decimal Equivalent
Given a singly linked list of 0s and 1s, find and return its decimal equivalent.
Input Format :
Elements of the linked list ending with -1 (-1 not included)
Output Format:
Decimal equivalent of input LL
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 0 -1
Sample Output 1:
2
Sample Input 2:
1 0 1 -1
Sample Output 2:
5
*/

// Solution:
int decimal(Node<int> *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int res = 0;  
    while(head != NULL){  
        res = (res << 1) + head -> data;  
        head = head -> next;  
    }  
    return res;
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
	cout<<decimal(head1)<<endl;
	delete head1;
}
*/