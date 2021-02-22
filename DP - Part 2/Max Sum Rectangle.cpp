/* Code: Max Sum Rectangle
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n){
    int best_so_far = INT_MIN, current_so_far = 0; 
    for(int i = 0; i < n; i++){
        current_so_far = current_so_far + arr[i]; 
        if(best_so_far < current_so_far){
            best_so_far = current_so_far;    
        }
        if(current_so_far < 0){
            current_so_far = 0;   
        } 
    } 
    return best_so_far; 
}

int main(){
    int n ,m;
    cin >> n >> m;
    int dp[n + 1][m + 1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> dp[i][j];
        }
    }
    int sum[n] = {0};
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int j = 0; j < m; j++){
        for(int i = 0 ; i < n; i++){
	        sum[i] = 0;
        }
        for(int l = j; l < m; l++){
            for(int k = 0; k < n; k++){
                sum[k] += dp[k][l];
            }
            curr_sum = kadane(sum, n);
            if(curr_sum > max_sum){
           		max_sum = curr_sum;            
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}
