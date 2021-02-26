/* Code : Check power of 4
You are given an integer N. You need to check if N is power of 4 or not. Return true or false accordingly.
Note : Do it in O(1) time.
Input Format :
Integers N 
Output Format :
true or false
Sample Input 1 :
4
Sample Output 1 :
true
Sample Input 2 :
8
Sample Output 2 :
false
*/

// Solution:
bool isPowerOf4(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n == 0){
        return false;
	}
    if((n & (n - 1)) != 0){
        return false;
	}
    else if((n & 0xAAAAAAAA) != 0){
        return false;
	}
    else{
        return true;
	}
}

// Main Code:
/*
#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	
    if(isPowerOf4(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	return 0;
}
*/
