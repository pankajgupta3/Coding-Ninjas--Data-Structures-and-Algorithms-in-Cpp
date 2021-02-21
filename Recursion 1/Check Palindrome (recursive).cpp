/* Code: Check Palindrome (recursive)
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

// Solution:
#include <bits/stdc++.h>
bool isPalindromeRec(char input[], int s, int e){
    if(s == e){
        return true;
    }
    if(input[s] != input[e]){
     	return false;
    }
    if(s <= e){
       return isPalindromeRec(input, s + 1, e - 1);
    }  
    return true;
}
bool checkPalindrome(char input[]){
   int n = strlen(input);
   if (n == 0){
     return true;
   }
   return isPalindromeRec(input, 0, n - 1);
}

// Main Code:
/*
#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
*/