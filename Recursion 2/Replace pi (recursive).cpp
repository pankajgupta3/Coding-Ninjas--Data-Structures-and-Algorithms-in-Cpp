/* Code: Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
*/

// Solution:
#include<bits/stdc++.h>
void replacePi(char input[]) {
	// Write your code here
	int n = strlen(input);
    if(n <= 1){
        return;
    }
    if(input[0] == 'p' and input[1] == 'i'){
        input[n + 2] = '\0';
    	for(int i = n - 1; i >= 2 ; i--){
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
    replacePi(input + 1);
}

// Main Code:
/*
#include <iostream>
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
*/ 
