/* Code: Reverse the First K Elements in the Queue
For a given queue containing all integer data, reverse the first K elements.
You have been required to make the desired change in the input queue itself.

Input Format :
The first line of input would contain two integers N and K, separated by a single space. They denote the total number of elements in the queue and the count with which the elements need to be reversed respectively.

The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.
Output Format:
The only line of output prints the updated order in which the queue elements are dequeued, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input queue itself.
Contraints :
1 <= N <= 10^6
1 <= K <= N
-2^31 <= data <= 2^31 - 1

 Time Limit: 1sec
Sample Input 1:
5 3
1 2 3 4 5
Sample Output 1:
3 2 1 4 5
Sample Input 2:
7 7
3 4 2 5 6 7 8
Sample Output 2:
8 7 6 5 2 4 3
*/

// Solution:
#include<stack>
using namespace std;
queue<int> reverseKElements(queue<int> &input, int k) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    stack<int> st;
    int i = k;
    while(i--){
        st.push(input.front());
        input.pop();
    }
    while(!st.empty()){
        input.push(st.top());
        st.pop();
    }
    i = input.size() - k;
    while(i--){
        input.push(input.front());
        input.pop();
    }
    return input;
}

// Main Code:
/*
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;

    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }

    queue<int> ans = reverseKElements(q, k);

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}
*/