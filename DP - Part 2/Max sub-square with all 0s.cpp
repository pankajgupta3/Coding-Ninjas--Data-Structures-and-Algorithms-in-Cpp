/* Code : Max sub-square with all 0s
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/

// Solution:
#include<iostream>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    /*
    Find the max square with all 0's
    */
    int dp[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < row; i++){
        if(arr[i][0] == 0){
            dp[i][0] = 1;
        }
        else{
            dp[i][0] = 0;
            ans = 1;
        }
    }
    for(int j = 0; j < col; j++){
        if(arr[0][j] == 0){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = 0;
            ans = 1;
        }
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(arr[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = min( min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i -1][j]) + 1;
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                }
            }
        }
    }
    return ans;
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
	delete[] arr;
	return 0;
}
*/
