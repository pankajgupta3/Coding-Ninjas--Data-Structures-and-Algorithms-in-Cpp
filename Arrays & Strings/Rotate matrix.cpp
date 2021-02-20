/*Code : Rotate matrix
Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
Try doing it without any extra space.
Note : You just need to change in the given input itself. No need to return or print anything.
Input format :
Line 1 : Integers N
Next N lines : N integers, elements of one row (separated by space)
Output Format :
Updated matrix
Constraints :
1 <= N <= 1000
Sample Input :
3
1 2 3
4 5 6
7 8 9
Sample Output :
3  6  9 
2  5  8 
1  4  7
*/

// SOLUTION:
void rotate(int **input, int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    int k;
    for(int i = 0; i < n; i++){
    	for(int j = i; j < n; j++){
            swap(input[i][j], input[j][i]);       
        }
    }

    for(int i = 0; i < n; i++){
        k = n - 1;
        for(int j = 0;j < k; j++){
            swap(input[j][i], input[k][i]);
            k--;
        }
    }
}

// Main Code:
/*
#include<iostream>
using namespace std;
#include "Solution.h"

int main() {
    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}
*/