/* Code: Print Keypad Combinations Code
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

// Solution:
#include<bits/stdc++.h>
using namespace std;
void printkeypadhelper(int num, string output, string options[10]){
	if(num == 0){
		cout << output << endl;
        return;
	}
	int digit = num % 10;
	int i = 0;
	while(i < options[digit].length()){
		printkeypadhelper(num / 10, options[digit][i] + output, options);
		i++;
	}
	return;
}
void printKeypad(int num){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string options[10]={"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	printkeypadhelper(num,"",options);
    return;
}

// Main Code:
/*
#include <iostream>
#include <string>
using namespace std;
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
*/