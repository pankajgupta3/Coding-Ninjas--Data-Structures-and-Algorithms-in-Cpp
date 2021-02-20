/*Code: Largest Unique Substring
Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.
Input Format :
String S
Output Format :
Largest unique substring
Constraints :
1 <= Length os String S <= 10^3
Sample Input:
abcdabceb
Sample Output:
dabce
*/

// SOLUTION:
#include <bits/stdc++.h>
using namespace std;
void findLargestUniqueSubstring(char input[], char output[]){
	// Write your code here
    string s(input);   
	int n = s.size();
    if(n == 0){
        return;
    }
    int i = 0;
    int j = 0;
    int freq[256] = {0};
    freq[s[0]]++;
	int count = 1;
	int ans_i = 0;
	while(j != n - 1){
		if(freq[s[j + 1]] == 0){
			j++;
			freq[s[j]] = 1;
			if(count < j - i + 1){
				count = j - i + 1;
				ans_i = i;
			}
		}
		else{
			freq[s[i]]--;
			i++;
		}
	}
	int z = 0;
    int k = 0;
	for(z = ans_i; z < ans_i + count; z++){
	    output[k++] = s[z];
	}
	output[k] = '\0';
}
// Main Code:
/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}
*/