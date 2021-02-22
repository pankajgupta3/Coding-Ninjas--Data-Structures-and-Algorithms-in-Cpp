/* Code: Tetrahedron
Given a tetrahedron with verticies A, B, C and D. An ant is standing at vertex D. The ant won't sit idle. It will keep on moving from one vertex to another along some edge of the tetrahedron. Your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (10^9 + 7).

Input Format :
Line 1 : Integer n (1 ≤ n ≤ 10^5) — the required length of the cyclic path
Output Format :
Return the only integer - the required number of ways modulo 1000000007 (10^9 + 7)
Sample Input :
2
Sample Output :
3
*/

// Solution:
#define mod 1000000007
long long solve(int n)
{
	long long dpA[n + 1], dpD[n + 1];
	dpA[0] = dpD[0] = dpD[1] = 0;
	dpA[1] = 1;

	for(int i = 2; i <= n; i++){
		dpA[i] = ((2 * dpA[i - 1]) % mod + dpD[i - 1] % mod);
		dpD[i] = (3 * dpA[i - 1]) % mod;
	}
	return dpD[n];
}

// Main Code:
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
}
*/