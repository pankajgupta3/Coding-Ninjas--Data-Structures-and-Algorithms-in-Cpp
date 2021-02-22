/* Code : Max sum sub-array
Send Feedback
Given an integer array containing both negative and positive integers. Find and return the sum of contiguous sub-array with maximum sum.
Input Format :
Line 1: Integer N, size of input array
Line 2: N integers, elements of input array (separated by space)
Output Format :
Maximum Sum of the contiguous sub-array
Contraints :
1 = N = 1000
-100 = A[i] <= 100
Sample Input 1:
3
1 2 3
Sample Output 1:
6
Sample Input 2:
4
-1 -2 -3 -4
Sample Output 2:
-1
*/

// Solution:
#include<climits> 
int findSum(int arr[],int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print output and return the output.
     * Taking input and printing output is handled automatically.
     */
    int best_so_far = INT_MIN, current_so_far = 0; 
    for(int i = 0; i < n; i++){
        current_so_far = current_so_far + arr[i]; 
        if(best_so_far < current_so_far){
            best_so_far = current_so_far;    
        }
        if(current_so_far < 0){
            current_so_far = 0;   
        } 
    } 
    return best_so_far; 
}

// Main Code:
/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);
    return 0;
}
*/