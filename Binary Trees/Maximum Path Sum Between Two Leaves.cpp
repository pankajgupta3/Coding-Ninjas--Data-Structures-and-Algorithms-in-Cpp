/* Problem: Maximum Path Sum Between Two Leaves
Given a binary tree of N nodes, find and return the maximum sum path between two leaves of the given tree.
Given binary tree contains positive values only.
Note: If there is only one leaf in the tree, then return 0 as answer.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Maximum sum path between two leaves
Constraints :
1 <= N <= 10^5
Sample Input :
10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Sample Output :
40
*/

// Solution:
long long int max_path = 0;
long long int dfs(BinaryTreeNode<int>* root){
	if(root == NULL){
        return 0;
    }
	long long int l = 0, r = 0;
	if(root -> left != NULL){
		l = dfs(root -> left);
    }
	if(root->right != NULL)
		r = dfs(root -> right);
	if(root-> left != NULL and root -> right != NULL){
		max_path = max(max_path, l + r + root -> data);
	}
	return max(l, r) + root -> data;
}
long long int maximumSumLeafpath(BinaryTreeNode<int>* root)
{
	dfs(root);
	return max_path;
}

// Main Code:
/*
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
using namespace std;
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << maximumSumLeafpath(root) << endl;
}
*/