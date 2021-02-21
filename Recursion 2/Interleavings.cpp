/* Code: Interleavings
Send Feedback
Given two strings S (of length m) and T (of length n), you need to find and print out all the possible inter leavings that are possible of length (m + n).
Inter leaving means - all possible combination of characters from both strings such that it contain all characters from both strings and, the respective ordering of characters of one string should remain same as in original.
For eg.
S = ab
T = cd
You need to find all strings of length 4 that contain all characters 'a', 'b', 'c' & 'd'. The only constraint on ordering of characters is - 'a' should always come before 'b' and 'c' should always come before 'd'.
Note : Print all strings in different lines.
Sample Input :
abc
def
Sample Output :
abcdef
abdcef
abdecf
abdefc
adbcef
adbecf
adbefc
adebcf
adebfc
adefbc
dabcef
dabecf
dabefc
daebcf
daebfc
daefbc
deabcf
deabfc
deafbc
defabc
*/

// Solution:
#include<bits/stdc++.h>
void printInter(char* first, char* second, char* res, int i = 0){
    if(*first == '\0' and *second =='\0'){
        res[i] = '\0';
        cout << "\n" << res;
    }
    if(*first != '\0'){
        res[i] = *first;
        printInter(first + 1, second, res, i + 1);
    }
    if(*second != '\0'){
        res[i] = *second;
        printInter(first, second + 1, res, i + 1);
    }
}
void interleaving(char* first, char* second){
     char* res = new char[strlen(first) + strlen(second) + 1];
     printInter(first, second, res, 0);
 }

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}
*/