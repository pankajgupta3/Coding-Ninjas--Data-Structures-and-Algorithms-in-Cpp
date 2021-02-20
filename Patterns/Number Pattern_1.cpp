/* Number Pattern
Print the following pattern
Pattern for N = 4
       1
      23
     345
    4567
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :
          1
         23
        345
       4567
      56789
*/

#include<iostream>
using namespace std;
int main(){
    int n, s, num;
    cin >> n;
    int row = n;
    for(int i = 1; i <= row; i++){
        s = row - i;
        num = i;

        for(int j = 1; j <= row - i; j++){
            cout << " ";
        }
        for(int j = row - i + 1; j <= row; j++){
            cout << num;
            num++;
        }
        cout << endl;
    }
	return 0;
}