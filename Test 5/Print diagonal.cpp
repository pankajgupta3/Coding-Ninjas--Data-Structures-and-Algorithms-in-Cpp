/* Problem: Print diagonal
Given a binary tree, print all the diagonal elements in a binary tree belonging to same line with slope equal to -1.

Input format :
Elements in level order form (separated by space) 
(If any node does not have left or right child, take -1 in its place) 
Output Format :
Elements are printed diagonally,(separated by space). Each diagonal level in new line.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 
Sample Output 1:
8 10 14
3 6 7 13
1 4
*/

// Solution:
void PrintDiagonal(BinaryTreeNode<int>* root) {
	// Don't write main().
	// Write your code here.
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    while(root != NULL){
        cout << root -> data << " ";
        if(root -> left){
            q.push(root -> left);
        }
        root = root -> right;
    }
    cout << endl;
    while(!q.empty()){
        int size = q.size();
        while(size > 0){
            root = q.front();
            q.pop();
            while(root != NULL){
                cout << root -> data << " ";
                if(root -> left){
                    q.push(root -> left);
                }
                root = root -> right;
            }
            size--;
        }
        cout << endl;
    }
    cout << endl;
}

// Main Code:
/*
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
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

BinaryTreeNode<int>* takeInputLevelWise(){
    queue< BinaryTreeNode<int>*  > pendingNodes;
    int rootData;
    cin >> rootData;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* currentNode =  pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if(leftData != -1 ){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(leftChild);
            currentNode->left = leftChild;
        }
        int rightData;
        cin >> rightData;
        if(rightData != -1 ){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(rightChild);
            currentNode->right = rightChild;
        }
    }
    return root;
}


void printlevelwise(BinaryTreeNode<int> *root)
{
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>* >pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(0);
    cout<<root->data<<endl;
    BinaryTreeNode<int>* top=NULL;
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>*q1=pendingNodes.front();
        pendingNodes.pop();
        BinaryTreeNode<int>*q2=pendingNodes.front();
        if(q1==0)
        {
            return;
        }
        if(q2==0)
        {
            pendingNodes.pop();
        }
        if (q1->left!=0)
        {
            pendingNodes.push(q1->left);
            cout<<q1->left->data<<' ';
        }
        if(q1->right!=0)
        {
            pendingNodes.push(q1->right);
            cout<<q1->right->data<<' ';
            if(q2==0)
            {
                pendingNodes.push(0);
            }
        }
        else
        {
            if(q2==0)
            {
                pendingNodes.push(0);
            }
        }
        if(q2==0)
        {
            cout<<endl;
        }
    }
}

int main()
{
	BinaryTreeNode<int>*root=takeInputLevelWise();
	PrintDiagonal(root);
}
*/