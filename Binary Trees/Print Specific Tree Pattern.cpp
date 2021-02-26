/* Problem: Print Specific Tree Pattern
Given a "complete" binary tree , print the following pattern using its all nodes.
root element
first element of second level
last element of  of second level
first element of the of the third level
last element of the third level
second element of the third level
second from last element of the third level
..... So on.

Input Format
Line 1: Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output Format
Required pattern
Constraint
Given binary tree is complete
1 <= Number of Nodes <= 10^6
1 <= value of each node <= 10^8
Sample Input 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
*/

// Solution:
nclude<bits/stdc++.h>
using namespace std;
void printSpecificPattern(BinaryTreeNode<int> * root)
{
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";

    queue<BinaryTreeNode<int>*>Q1, Q2;
    if(root -> left){
    	Q1.push(root -> left);
    }
    if(root -> right){
    	Q2.push(root -> right);
    }

    while(!Q1.empty()){
        int n = Q1.size();
        while(n--){
            BinaryTreeNode<int>* x = Q1.front();
            Q1.pop();
            cout << x -> data << " ";
            if(x -> left){
           	    Q1.push(x -> left);
            }

            if(x -> right){
           		Q1.push(x -> right);
           }
           BinaryTreeNode<int>* y = Q2.front();
           Q2.pop();
           cout << y -> data << " ";
           if(y->right){
               Q2.push(y -> right);
           }
           if(y->left){
           	   Q2.push(y -> left);
           }
        }
    }
}
