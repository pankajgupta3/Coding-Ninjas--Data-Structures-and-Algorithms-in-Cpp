/* Code: Dequeue
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
*/

// Solution:
class Deque {
    // Complete this class
    int *dequeue;
    int frontIndex;
    int rearIndex;
    int size;

public:
    Deque(int size){
        frontIndex = -1;
        rearIndex = 0;
        dequeue = new int[size];
        this -> size = size;
    }

    void insertFront(int data){
        if(frontIndex == (rearIndex + 1) % size){
            cout << -1 << endl;
            return;
        }
		if(frontIndex == -1){
            frontIndex = 0;
            rearIndex = 0;
        }
        else{
            frontIndex = ((frontIndex - 1) % size + size) % size;
        }
        dequeue[frontIndex] = data;
    }

    void insertRear(int data){
        if(frontIndex == (rearIndex + 1) % size){
            cout << -1 << endl;
            return;
        }
		if(frontIndex == -1){
            frontIndex = 0;
            rearIndex = 0;
        }
        else{
        	rearIndex = (rearIndex + 1) % size;
        }
        dequeue[rearIndex] = data;
    }

    void deleteFront()
    {
        if(frontIndex == -1){
            cout << -1 << endl;
            return;
        }
        if(frontIndex == rearIndex){
            frontIndex = -1;
            rearIndex = -1;
        }
		else{
            frontIndex = (frontIndex + 1) % size;
        }        
    }

    void deleteRear(){
        if(frontIndex == -1){
            cout << -1 << endl;
            return;
        }
        if(frontIndex == rearIndex){
            frontIndex = -1;
            rearIndex = -1;
        }
		else{
            rearIndex = ((rearIndex - 1) % size + size) % size;
        }        
    }

    int getFront(){
        if(frontIndex == -1){
            return -1;
        }
        return dequeue[frontIndex];
    }

    int getRear(){
        if(frontIndex == -1){
            return -1;
        }
        return dequeue[rearIndex];
    }
};

// Main Code:
/*
// C++ implementation of De-queue using circular array
#include<iostream>
using namespace std;
// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    return 0;
}
*/