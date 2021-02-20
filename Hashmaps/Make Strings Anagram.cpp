/* Code: Make Strings Anagram
Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
Anagram of a string is a string which is its permutation.
For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
Input Format :
Line 1 : String1
Line 2 : String2
Output Format :
Number of deletions required
Contraints :
1<= Length of string <=10^4
Sample Input 1 :
cde 
abc
Sample Output 1 :
4
Sample Input 2 :
aab
aba
Sample Output 2 :
0
*/

// Solution:
#include<bits/stdc++.h>
int makeAnagram(char str1[], char str2[]){
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    unordered_map<char, int>m;
    int counter = 0;
    int n1 = 0;
    int n2 = 0;
    
    string s1 = str1;
    n1 = s1.length();
    
    string s2 = str2;
    n2 = s2.length();
    
    for(int i = 0; i < n1; i++){
        if(m.count(s1[i]) > 0){
            m[s1[i]]++;
        }
        else{
            m[s1[i]] = 1;
        }
    }

    for(int i = 0; i < n2; i++){
        if(m.count(s2[i]) > 0){   
            int x = m[s2[i]];
            m[s2[i]]--;
            if(x > 0){    
                counter++;
            }
        }
    }
    return (n1 + n2 - 2 * counter);
}

// Main Code:
/*
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
	
}
*/