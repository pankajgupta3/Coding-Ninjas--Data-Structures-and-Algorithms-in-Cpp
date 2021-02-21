/* Code: String to Integer
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

// Solution:
#include<bits/stdc++.h>
int stringToNumber(char input[]) {
    // Write your code here
	int n = strlen(input);
    if(n == 0){
        return 0;
    }
    int smallOutput = stringToNumber(input + 1);
    return (input[0] - '0') * pow(10, n - 1) + smallOutput;
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
*/