/* Problem: Max Priority Queue
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/

// Solution:
bits/stdc++.h>
class PriorityQueue {
    // Complete this class
    vector<int> pq;
    public:
    PriorityQueue()
    {
        
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    void insert(int element) 
    {
		pq.push_back(element);
		int childIndex = pq.size() - 1;
		while(childIndex > 0) 
        {
			int parentIndex = (childIndex - 1) / 2;
			if(pq[childIndex] > pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}
    int getMax()
    {    
        if(isEmpty())
        {
            return INT_MIN;
        }
        return pq[0];
    }
    int removeMax()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int PI = 0;
        int LCI = 2 * PI + 1;
        int RCI = 2 * PI + 2;
        while(LCI < pq.size()){
            int minIndex = PI;
            if(pq[minIndex] < pq[LCI]){
                minIndex = LCI;
            }
            if(pq[minIndex] < pq[RCI] && RCI < pq.size()){
                minIndex = RCI;
            }
            if(minIndex == PI){
                break;
            }
            
            int temp = pq[minIndex];
			pq[minIndex] = pq[PI];
			pq[PI] = temp;
			PI = minIndex;
			LCI = 2 * PI + 1;
			RCI = 2 * PI + 2;
        }
        return ans;
    }
};

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
*/