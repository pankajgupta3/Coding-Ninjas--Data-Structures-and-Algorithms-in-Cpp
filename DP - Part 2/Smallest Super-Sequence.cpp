/* Code: Smallest Super-Sequence
 Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
 The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
Note :
If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
Input Format:
The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
Output Format:
Length of the smallest super-sequence of given two strings. 
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
ab
ac
Sample Output 1 :
3
Explanation of Sample Output 1 :
Their smallest super sequence can be "abc" which has length = 3.
Sample Input 2 :
pqqrpt
qerepct
Sample Output 2 :
9
*/

// Solution:
int smallestSuperSequence(string str1, string str2)
{
	//Write your code here
    int len1 = str1.size();
    int len2 = str2.size();
	int dp[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++){ 
        for(int j = 0; j <= len2; j++){ 
            if (i == 0){
                dp[i][j] = j; 
            } 
            else if(j == 0){
                dp[i][j] = i; 
            } 
            else if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1]; 
            } 
            else{
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); 
            }
    	}
    } 
    return dp[len1][len2];
}

// Main Code:
/*
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}
*/