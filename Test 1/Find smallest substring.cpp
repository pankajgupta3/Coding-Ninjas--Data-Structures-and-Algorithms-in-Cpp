/* Code: Find smallest substring
Given two strings string1 and string2 (named large and small), find the smallest substring in string1 containing all characters of string2 in O(n). You need to return the output substring.
Note : The characters of string2 need not to be present in same order in string1. That is, we need a substring which contains all characters of string2 irrespective of the order.
Return null if no substring with all characters is present.
Input format :
Line 1 : String 1
Line 2 : String 2
Output Format :
Smallest substring
Constraints :
1 <= Length of string1 & string2 <= 10^4
Sample Input 1 :
Looks for minimum string
mums
Sample Output 1 :
mum s
*/

// Solution:
#include<bits/stdc++.h>
char* findMinSubstringContainingString(char *large, char *small){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print anything
     * Taking input and printing output is handled automatically.
     */
    string small_s(small);
    string large_s(large);
    int size_l= large_s.size();
    int size_s = small_s.size();
	vector<int> dict(128, 0);
    for(auto c : small_s){
        dict[c]++;
    }
    int start = 0, end = 0, count = 0;
    int m_len = INT_MAX, m_start = 0;
    while(end < size_l) {
        if(dict[large_s[end]] > 0){
            count++;   
        }
        dict[large_s[end]]--;
        end++;
        while(count >= size_s){
            if(end - start < m_len){
                m_start = start;
                m_len = end - start;
            }
            dict[large_s[start]]++;
            if(dict[large_s[start]] > 0){
                count--;
            }
            start++; 
    	}
    }
    if(m_len < INT_MAX){
        string s1 = large_s.substr(m_start, m_len);
        for(int i = 0; i < s1.length(); i++){
            large[i] = s1[i];
        }
        large[s1.length()] = '\0';
        return large;
    }  
    return NULL;
}

// Main Code:
/*
#include <iostream>
using namespace std;
int main() {
    char S[1000000], T[1000];
    cin.getline(S, 1000000);
    cin.getline(T, 1000);
    char *ans = findMinSubstringContainingString(S, T);
    if(ans) {
	    cout << ans << endl;
    }
    else {
	    cout << "null" << endl;
    }
}
*/