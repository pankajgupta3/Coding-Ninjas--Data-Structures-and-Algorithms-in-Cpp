/* Pattern: Triangle of numbers
Print the following pattern for the given number of rows.
Pattern for N = 4
           1
          232
         34543
        4567654

The dots represent spaces.

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Constraints :
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
           1
          232
         34543
        4567654
       567898765
*/

#include<iostream>
using namespace std;
int main(){
    int n, num1, num2, p;
    cin >> n;
    for(int i = 1; i <= n; i++){
        num1 = i;
        num2 = i - 1;
		p = i;
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        for(int j = n - i + 1; j <= n; j++){
            cout << p;
            p++;
        }
        for(int j = n + 1; j <= n + i - 1; j++){
            p--;
            cout << p - 1;
        }
        for(int j = n + i; j <= 2 * n - 1; j++){
            cout << " ";
        }
        cout << endl;
    }
	return 0;
}

