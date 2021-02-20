/*Code : Compress the string
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
Exmple:
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".

The string is compressed only when the repeated character count is more than 1.
Note :
Consecutive count of every character in the input string is less than or equal to 9.
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aaabbccdsa
Sample Output 1:
a3b2c2dsa
Sample Input 2:
aaabbcddeeeee
Sample Output 2:
a3b2cd2e5
*/

// SOLUTION:
void stringCompression(char input[]) {
    // Write your code here
    int count = 1;
    char currentChar = input[0];
    int nextIndex = 1;
    for(int i = 1; input[i] != '\0'; i++){
        if(input[i] == currentChar){
            count++;
        }
        else{
            if(count > 1){
                input[nextIndex++] = char(count + 48);
            }
            currentChar = input[i];
            input[nextIndex++] = input[i];
            count = 1;
        }
    }
    if(count > 1){
        input[nextIndex++]=char(count + 48);
    }
    input[nextIndex]='\0';
}

// Main Code:
/*
#include <iostream>
#include <cstring>
using namespace std;

#include "solution.h"

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str;
}
*/