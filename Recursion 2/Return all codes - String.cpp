/* Code: Return all codes - String
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

// Solution:
#include<string>
using namespace std;
string s = "";
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.length() <= 0){
        output[0] = s;
        cout<<output[0]<<endl;
        return 0;
    }
    if(input.length() >= 1){
        char c = input[0] - '0' + 96;
        s += c;
        int p = getCodes(input.substr(1), output);
        s = s.substr(0, s.size() - 1);
    }
    if(input.length() >= 2){
        if((input[0]-'0') == 2 and (input[1] - '0') <= 6 or (input[0] - '0') == 1 and (input[1] - '0') <= 9){
            int a, b, c;
            a = input[0] - '0';
            b = input[1] - '0';
            c = 10 * a + b;
            char d = c + 96;
            s += d;
            int q = getCodes(input.substr(2), output);
            s = s.substr(0, s.size() - 1);
        }
    }
    return 0;
}

// Main Code:
/*
#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
*/