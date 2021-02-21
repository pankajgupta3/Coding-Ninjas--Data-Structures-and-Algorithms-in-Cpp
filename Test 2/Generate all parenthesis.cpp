/* Code: Generate all parenthesis
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
Input format :
Integer n
Output format :
Print all possible valid parenthesis in different lines
Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.
Constraints :
1 <= n <= 10
Sample Input :
3
Sample Output :
((()))
(()())
(())()
()(())
()()()
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;
void printWellFormedParenthesis(int open, int closed, char str[]){
	if(closed == 0){
		cout << str << endl;
		return;
	}
	if(open > 0){
		char* str1 = new char[strlen(str) + 2];
		strcpy(str1, str);
		int len = strlen(str1);
		str1[len] = '(';
		str1[len + 1] = '\0';
		printWellFormedParenthesis(open - 1, closed, str1);
	}
	if(closed > open){
		char *str1 = new char[strlen(str) + 2];
		strcpy(str1, str);
		int len = strlen(str1);
		str1[len] = ')';
		str1[len + 1] = '\0';
		printWellFormedParenthesis(open, closed - 1, str1);
	}
}
void printWellFormedParanthesis(int n){
    // Write your code here
    char str[]={'\0'};
	printWellFormedParenthesis(n, n, str);
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    printWellFormedParanthesis(n);
}
*/