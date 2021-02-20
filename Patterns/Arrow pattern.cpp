/* Arrow pattern
Print the following pattern for the given number of rows.
Assume N is always odd.
Note : There is space after every star.
Pattern for N = 7
*
 * *
   * * *
     * * * *
   * * *
 * *
*
Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Sample Input :
11
Sample Output :
*
 * *
   * * *
     * * * *
       * * * * *
         * * * * * *
       * * * * *
     * * * *
   * * *
 * *
*

*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= (n + 1) / 2; i++){
        for(int j = 1; j <= i - 1; j++){
            cout << " ";
        }
        for(int j = i; j <= 2 * i - 1; j++){
            cout << "* ";
        }
        for(int j = 2 * i; j <= n;j++){
            cout << " ";
        }
        cout << endl;
    }
    for(int i = (n + 1) / 2 - 1; i >= 1; i--){
        for(int j = 1; j <= i - 1; j++){
            cout << " ";
        }
        for(int j = i; j <= 2 * i - 1;j++){
            cout << "* ";
        }
        for(int j = 2 * i; j <= n; j++){
            cout << " ";
        }
        cout << endl;
    }
}

