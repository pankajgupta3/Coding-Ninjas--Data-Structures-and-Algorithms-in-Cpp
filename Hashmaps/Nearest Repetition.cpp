/* Code: Nearest Repetition
Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
Input Format :
Line 1 : Integer N, Size of array
Line 2 : Elements of the array (separated by space)
Output Format :
Print the minimum distance 
Contraints :
1<= N <=10^6
Sample Input 1:
6
1 3 1 5 4 3
Sample Output 1:
2
Sample Input 2:
7
5 47 82 4 4 6 2 
Sample Output 2:
1
*/

// Solution:
#include<unordered_map>
int minDistance(int arr[],int n){
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    unordered_map<int, int>m;
    int min = n;
    for(int i = 0; i < n; i++){
        if(m.find(arr[i]) != m.end()){
            if(min > (i - m[arr[i]])){
                min = i - m[arr[i]];
            }
        }
    	m[arr[i]] = i;
    }
    return min;
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
    	cout << minDistance(arr,n);
}
*/