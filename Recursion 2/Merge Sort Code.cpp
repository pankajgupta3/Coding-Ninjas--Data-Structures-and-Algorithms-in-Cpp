/* Code: Merge Sort Code
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

// Solution:
void merge(int input[], int si, int ei){
    int size = ei - si + 1;
    int output[size];
	int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    while(i <= mid and j <= ei){
        if(input[i] > input[j]){
            output[k++] = input[j++];
        }
        else{
            output[k++] = input[i++];
        }
    }
    while(i <= mid){
        output[k++] = input[i++];
    }
    while(j <= ei){
        output[k++] = input[j++];
    }
    int m = 0;
    for(int i = si; i <= ei; i++){
        input[i] = output[m++];
    }
}
void mergeSortHelper(int input[], int si, int ei){
    if(si >= ei){
        return;
    }
    int mid = (si + ei) / 2;
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid + 1 , ei);
    merge(input, si, ei);
}
void mergeSort(int input[], int size){
	// Write your code here    
    mergeSortHelper(input, 0, size - 1);
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
*/