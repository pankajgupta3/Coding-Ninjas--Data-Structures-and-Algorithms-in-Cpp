/*Code: Reverse string Word Wise
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
*/

// SOLUTION:
using namespace std;
void reverse(char input[], int start, int end){
    while(start < end){
        swap(input[start++], input[end--]);
    }
}
void reverseStringWordWise(char input[]) {
    // Write your code here
    int prev = -1;
    int i = 0;
    for(; input[i] != '\0'; i++){
        if(input[i] == ' '){
            reverse(input, prev + 1, i - 1);
            prev = i;
        }
    }
    reverse(input, prev + 1, i - 1);
    reverse(input, 0, i - 1);
}

// Main Code:
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
*/