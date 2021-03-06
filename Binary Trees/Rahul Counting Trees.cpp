/* Problem: Rahul Counting Trees
You are given a Binary tree T and an integer K. Input binary Trees T is consisting of N (numbered from 1 to N) nodes rooted at node 1 and each node has a number written on it, where the number written on the ith node is A[i].
Now, Rahul needs to find the number of unordered triplets (i,j,k), such that node i is an ancestor of node j as well as node k, and A[i]+A[j]+A[k]>=K
A node x is considered an ancestor of another node y, if x is parent of y or x is an ancestor of parent of y.
Help Rahul for the same.
Input Format :
Line 1 : 2 space separated integers N and K. 
Line 2 : N space separated integers, where the ith integer denotes A[i].
Line 3 : N-1 space separated integers, where the ith integer represents the parent of node i+1.
Output Format :
Print the required answer on a single line.
Contraints :
1<= N <= 500
0<= A[i] <=10^9
Sample Input 1 :
5 6
1 2 3 4 5
1 2 2 1
Sample Output 1 :
7
Sample Input 2 :
20 63
66 1 20 77 66 71 5 17 12 49 51 14 8 41 54 45 54 77 26 17
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
Sample Output 2 :
252
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y;
    cin >> n >> y;
    long long int val[n + 1], par[n + 1], root;
    long long int a[n + 1][n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin >> val[i];  
    }
    root = 1;
    par[1] = 1;
    for(int i = 2; i <= n; i++){
       cin >> par[i]; 
    }
    for(int i = 2; i <= n; i++){
        int x = par[i];
        a[x][i] = 1;
        while(x != root){
            x = par[x];
            a[x][i] = 1;
        }
    }
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(a[i][j] == 1 && a[i][k] == 1 && i != j && i != k && j != k && val[i] + val[j] + val[k] >= y)
                ans++;
            }
        }
    }
    cout << ans / 2;
    return 0;
}
