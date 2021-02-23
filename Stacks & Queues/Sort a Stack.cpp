/* Code: Sort a Stack
Given a stack, sort the elements inside that stack in ascending order using only push and pop operation. You can use one additional stack only.
For eg.

Input Stack :  5 (top)
               4
               3
               2
               1
Output Stack : 1 (top)
               2
               3
               4
               5
Input format
First line of input consists of an integer representing the size of the stack, N
Second line of input consistes of N space-separated integers representing the elements of the stack
Output format
The only line of output consists of the elements of the stack in sorted order (space-separated)
Constraints
0 <= N <= 1000
Time limit: 1 sec
Sample Input
5
1 2 3 4 5
Sample Output
1 2 3 4 5
*/

// Solution:
#include <stack>
using namespace std;
void sortStack(stack<int> &s){
	// Write your code here 
    stack<int> helper; 
    while(!s.empty()){ 
        int temp = s.top(); 
        s.pop(); 
        while(!helper.empty() and helper.top() < temp){ 
            s.push(helper.top()); 
            helper.pop(); 
        } 
        helper.push(temp); 
    }
    while(!helper.empty()){ 
        cout << helper.top() << " "; 
        helper.pop(); 
    } 
}

// Main Code:
/*
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}
*/