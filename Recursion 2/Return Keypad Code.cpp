/* Code: Return Keypad Code
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1){
         return 1;
    }
    int num1 = num % 10;
    string s;
    
    if(num1 == 2){
        s = "abc";
    }
    else if(num1 == 3){
        s = "def";
    }
    else if(num1 == 4){
        s = "ghi";
    }
    else if(num1 == 5){
        s = "jkl";
    }
    else if(num1 == 6){
        s = "mno";
    }
    else if(num1 == 7){
        s = "pqrs";
    }
    else if(num1 == 8){
        s = "tuv";
    }
    else{
        s = "wxyz";
    }
    string b[1000];
    
    int smalllength = keypad(num / 10, b);
    int len = s.length();
    int k = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < smalllength; j++){
            output[k] = b[j] + s[i];
            k++;
        }
    }
    return k;
}

// Main Code:
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
*/