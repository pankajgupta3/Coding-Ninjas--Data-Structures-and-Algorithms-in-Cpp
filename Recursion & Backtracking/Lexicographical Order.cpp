/* Code: Lexicographical Order
Given a number n, print numbers from 1 to n in dictionary(lexicographical) order.
Sample Input
20
Sample Output
1
10
11
12
13
14
15
16
17
18
19
2
20
3
4
5
6
7
8
9
*/

// Solution:
#include <iostream>
using namespace std;
void lexicographicalOrderHelper(int numberSoFar, int num){
    if(numberSoFar > num){
        return;
    }
    cout << numberSoFar << endl;
    for(int i = 0; i <= 9; i++){
        lexicographicalOrderHelper(numberSoFar * 10 + i, num);
    }
}
void lexicographicalOrder(int num){
	// Write your code here
	for(int i = 1; i <= 9; i++){
        lexicographicalOrderHelper(i, num);
    }
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}
*/