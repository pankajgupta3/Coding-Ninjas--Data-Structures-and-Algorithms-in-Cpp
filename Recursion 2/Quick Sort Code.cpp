/* Code: Quick Sort Code
Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

// Solution:
int partitionArray(int input[],int start,int end){
    int pivot = input[start];
    int count = 0;
    for(int i = start + 1; i <= end; i++){
        if(input[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    int temp = input[start];
    input[start] = input[pivotIndex];
    input[pivotIndex] = temp;
        
    int i = start, j = end;
    while(i <= pivotIndex && j >= pivotIndex){
        while(input[i] <= pivot){
            i++;
        }
        while(input[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
	return pivotIndex;             
}
void quickSort(int input[], int start, int end){
    if(start >= end){ 
        return;
    }
    int pivotIndex = partitionArray(input, start, end);
    quickSort(input, start, pivotIndex - 1);
    quickSort(input, pivotIndex + 1, end);
}
void quickSort(int input[],int n)
{
    quickSort(input, 0, n - 1);
}

// Main Code:
/*
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;
}
*/