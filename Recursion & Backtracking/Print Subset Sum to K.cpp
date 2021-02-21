/* Code: Print Subset Sum to K
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

// Solution:
#include <bits/stdc++.h> 
using namespace std; 
void printSubsetSumToKHelper(int input[], int size, vector<int> v, int k){ 
    if(k== 0){
        for(int i = v.size() - 1; i >= 0; i--){
            cout << v[i]<< " "; 
        } 
        cout << endl; 
        return; 
    } 
    if(size == 0){
        return;
    } 
    printSubsetSumToKHelper(input, size - 1, v, k); 
    v.push_back(input[size - 1]); 
    printSubsetSumToKHelper(input, size - 1, v, k - input[size - 1]); 
} 

void printSubsetSumToK(int input[], int size, int k) {
    vector<int> v;
    printSubsetSumToKHelper(input, size, v, k); 
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
*/