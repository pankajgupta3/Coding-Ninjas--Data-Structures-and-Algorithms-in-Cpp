/* Problem: Boundary Traversal
Given a binary tree having N nodes, print its boundary traversal.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Boundary traversal (separated by space)
Constraints :
1 <= N <= 10^5
Sample Input 1 :
1 2 3 -1 -1 -1 -1
Sample Output 1 :
1 2 3
Sample Input 2 :
1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
Sample Output 2 :
1 2 4 6 8 7 3
*/

// Solution:
void printBoundaryLeft(BinaryTreeNode<int>* root){
	if(root != NULL){
		if(root -> left != NULL){
			cout << root -> data << " ";
			printBoundaryLeft(root -> left);
		}
		else if(root -> right != NULL){
			cout << root -> data << " ";
			printBoundaryLeft(root -> right);
		}
	}
}

void printBoundaryRight(BinaryTreeNode<int>* root){
	if(root != NULL){
		if(root -> right != NULL){	
			printBoundaryRight(root -> right);
			cout << root -> data << " ";
		}
		else if(root->left != NULL){	
			printBoundaryRight(root -> left);
			cout << root -> data << " ";
		}
	}
}

void printLeaves(BinaryTreeNode<int>* root){
	if(root != NULL){
		printLeaves(root -> left);
		if(root -> left == NULL and root -> right == NULL){
			cout << root -> data << " ";
        }
		printLeaves(root -> right);
	}
}

void printBoundary(BinaryTreeNode<int>* root){
	if(root != NULL){
		cout << root -> data << " ";
		printBoundaryLeft(root -> left);
		printLeaves(root -> left);
		printLeaves(root -> right);
		printBoundaryRight(root -> right);
	}
}

void solve(BinaryTreeNode<int>* root)
{
	printBoundary(root);
	cout << endl;
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
    solve(root);
}
*/