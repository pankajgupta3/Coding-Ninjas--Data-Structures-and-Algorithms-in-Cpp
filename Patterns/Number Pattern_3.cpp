/* Number Pattern
Print the following pattern
Pattern for N = 4
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input 1 :
5
Sample Output 1 :
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 
*/

// Code
void printPattern(int n){
	/* Don't write main().
 	Don't read input, it is passed as function argument.
	Print pattern as per the question.
	*/  
    int len = n * 2 - 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            int min = i < j ? i : j;
            min = min < len - i ? min : len - i - 1;
            min = min < len - j - 1 ? min : len - j - 1;
            cout << n - min << " ";
        }
        cout << endl;
    }
}

// Main Code
/*
#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  printPattern(n);
}
*/


