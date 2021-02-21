/* Code : No. of numbers - with duplicates
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :
Integer n
Output Format :
Count of greater numbers
Sample Input :
122
Sample Output :
2
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;

long findDuplicates(int* arr,int n,long* fact,int* freq,long div)
{
    if(n==0 || n == 1) return 0;
    
    long ans = 0;
    for(int i = arr[0] + 1; i < 10; i++){
        if(freq[i] > 0){
            long div_temp = div / freq[i];
            ans += fact[n - 1] / div_temp; 
        }
    }
    
    div = div / freq[arr[0]];                        

    freq[arr[0]]--;
    
    ans += findDuplicates(arr + 1, n - 1, fact, freq, div);
    return ans;
}
    
long numberOfNumbersWithDuplicates(long num)
{
    int arr[100];
    int k = 0; 
    while(num != 0){
        arr[k++] = (num % 10);
        num = num / 10;
    }
    
    int i1 = 0, j1 = k - 1;
    while(i1 <= j1){
        swap(arr[i1], arr[j1]);
        i1++;
        j1--;
    }
    
    int n = k;
    long fact[n + 1];
    fact[0] = 1;
    
    int freq[10] = {0};
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
        fact[i + 1] = (i + 1) * fact[i];    
    }
    
    long div = 1;
    for(int j = 0; j < 10; j++){
        if(freq[j])
            div *= fact[freq[j]];
    }
    return findDuplicates(arr, n, fact, freq, div);
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}
*/