/* Number Pattern
Print the following pattern for n number of rows.
For eg. N = 5

1        1
12      21
123    321
1234  4321
1234554321

Sample Input 1 :
4
Sample Output 1 :
1      1
12    21
123  321
12344321
*/

#include<iostream>
using namespace std;
int main(){
	int n;
    cin >> n;
	
    for(int i = 1; i <= n;i++){	
    	int p = i;
        for(int j = 1; j <= i; j++){
            cout << p - i + 1;
            p++;
        }
        for(int j = i + 1; j <= 2 * n - i; j++){
            cout << " ";
        }
        for(int j = 2 * n - i + 1; j <= 2 * n; j++){
            cout << p - i;
            p--;
    	}
        cout<<endl;
    }
    return 0;
}
