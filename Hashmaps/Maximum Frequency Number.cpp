/* Code: Maximum Frequency Number
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

// SOLUTION:
#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int>our_map;
    for(int i = 0; i < n; i++){
        int key = arr[i];
        if(our_map.count(key) == 0){
            our_map[key]=1;
		}
        else{
            our_map[key]++;
		}
	}
    int max = our_map[arr[0]];
    int res = arr[0];
    int j = 1;
    while(j < n){
        if(our_map[arr[j]] > max){
            max = our_map[arr[j]];
            res = arr[j];
        }
        j++;
    }
    return res;
}

// Main Code
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}*/