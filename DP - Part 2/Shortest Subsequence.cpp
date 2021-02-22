/* Code: Shortest Subsequence
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/

// Solution
int solve(string S,string V)
{
	int n = S.size();
    int m = V.size();
    int prev;
	int dp[n + 1][m + 1];
    int next[n + 1][m + 1];
	for(int i = 0; i < n; i++){
		prev = -1;
		for(int j = 0; j < m; j++){
			if(S[i] == V[j]){
                prev = j;
            }
			next[i + 1][j + 1] = prev;
		}
	}
	for(int i = 1; i < n; i++){
		dp[i][0] = 1;
	}
	for(int i = 0; i <= m; i++){
		dp[0][i] = 1e9;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(next[i][j] == -1){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
			}
		}
	}
	return dp[n][m];
}

// Main Code:
/*
#include <iostream>
#include <string>
#include "solution.h"

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
*/