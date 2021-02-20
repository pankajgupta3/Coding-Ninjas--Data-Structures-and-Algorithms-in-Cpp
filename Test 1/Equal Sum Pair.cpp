/* Code: Equal Sum Pair
Given an integer array of size N, determine whether 4 elements exist such that a+b = c+d. Return true or false accordingly.
Perform this in O(n^2).
Note : (a+b) and (c+d) is unique. For eg, array(10, 10, 8, 9) Pair(10(at index 0),8) and Pair(10(at index 1),8) are different pairs but Pair(10(index 0),10(index 1)) and Pair(10(index 1),10(index0)) are same.
Input Format :
Integer N (size of input array)
Output Format :
true or false
Contraints :
1<= N <=10^3
Sample Input 1:
6
9 8 17 20 30 40
Sample Output 1:
false
Sample Input 2:
6
9 8 7 10 20 30
Sample Output 2:
true
Sample Output 2 Explanation :
9+8 = 10+7
Hence 4 elements exist which satisfy this relation.
Sample Input 3:
6
100 250 3 3 600
Sample Output 3:
true
Sample Output 3 Explanation :
100+3 (3 at index 1) = 100+3 (3 at index 2)
*/

// Solution:
#include<iostream>
#include<unordered_map>
using namespace std;
bool findPairs(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    unordered_map<int, bool> m;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(m.find(sum) != m.end()){
                return true;
            }
            else{
                m[sum] = true;
            }
        }
    }
    return false;     
}

// Main Code:
/*
#include <cmath>
#include <iostream>
using namespace std;
int main() {
	int n=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    if(findPairs(arr,n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
*/