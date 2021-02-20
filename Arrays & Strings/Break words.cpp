/* Code: Break words
You are given a sentence contained in given string S. Write a function which will replace all the words within the sentence whose length is even and greater than equal to 4, with a space between the two equal halves of the word.
Space complexity should be O(1).
Input Format :
String S
Output Format :
Updated string
Constraints :
1 <= Length of S <= 10000
Sample Input :
Helloo world good morniing
Sample Output :
Hel loo world go od morn iing
*/

// SOLUTION:
void breakWords(char* S)
{
	/*
	 * Don't write main.
	 * Don't return or print anything.
	 * Changes should be done in the given string.
	*/
    int len;
    int i=0;
    int n = strlen(S);
    while(i < n){
        len = 0;
        int j = i;
        while(S[j] != ' ' && j < n){
            len++;
            j++;
        }
        int t = j;

        if(len >= 4 && len%2 == 0){
            int k = n;
            j = i + len/2;
            while(k > j){
                S[k] = S[k - 1];
                k--;
             }
             n++;
             S[j]=' ';
         }
         i = t + 1;
    }
}

// Main Code
/*
#include<iostream>
#include<string.h>
using namespace std;
#include"solution.h"
int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}
*/