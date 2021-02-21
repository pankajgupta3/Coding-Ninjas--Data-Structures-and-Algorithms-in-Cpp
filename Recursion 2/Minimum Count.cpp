/* Code: Minimum Count
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 50
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;
int minCount(int n){
    if(n <= 1){
        return n; 
    }
    int res = n;
    for(int x = 1; x <= n; x++){
        int temp = x * x; 
        if (temp > n){
           break;    
        }
        else{
           res = min(res, 1 + minCount(n - temp)); 
        }     
    }
    return res; 
}

// Main Code:
/*
#include<iostream>
using namespace std;
#include "Solution.h"
int main(){
  int num;
  cin >> num;
  cout << minCount(num);
}

*/
