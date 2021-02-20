/* Code: Longest Subset
Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
Input Format :
Line 1 : Integer N, size of array
Line 2 : Array elements (separated by space)
Output Format :
Length of longest subarray
Contraints :
1<= N <=10^6
Sample Input 1 :
6 
1 0 0 1 1 1
Sample Output 1 :
4    
Sample Input 2 :
10 
1 1 1 0 0 0 1 1 0 0
Sample Output 2 :
10
*/

// Solution:
#include<unordered_map>
int max(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ans = 0;
    unordered_map<int, int>m;
    m[0] = -1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
		}		
	}
	
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(m.find(sum) != m.end()){
         	if(ans < i - m[sum]){
                ans  = i - m[sum];
			}
		}
        else{
            m[sum] = i;
		}
	}
    return ans;
}

// Main Code:
/*
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	
    	cout << max(arr,n);
}
*/