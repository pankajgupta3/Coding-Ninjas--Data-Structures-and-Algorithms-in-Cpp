/* Problem: Depth of Binary Tree
A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.
The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.
Given the pre-order traversal of a nice binary tree as a string, you are required to find the depth of the tree.
Output one line for each test case, containing a single integer, the depth of tree.
*/

// Solution:
int depthHelper(char str[], int n, int& i){ 
    if(i >= n or str[i] == 'l'){
        return 0; 
    }
  
    i++; 
    int left = depthHelper(str, n, i); 
  
    i++; 
    int right = depthHelper(str, n, i); 
  
    return 1 + max(left, right); 
}
int depth(char str[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int n = 0;
    for(int i = 0; str[i] != '\0' ; i++){
        n++;
    }
    int i = 0; 
    depthHelper(str, n, i);
}

// Main Code:
/*
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	char *str = new char[100000];
	cin>>str;
	cout<<depth(str);
	return 0;
}
*/
