/* Code: Second Largest Element In Tree
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format:
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/

// Solution:
TreeNode<int>* maxDataNode(TreeNode<int>* root){
    if(root == NULL){
        return root;
    }
	TreeNode<int>* max = root;
    for(int i = 0; i < root -> numChildren(); i++){
        TreeNode<int>* temp = maxDataNode(root -> getChild(i));
        if(max -> data < temp -> data){
            max = temp;
        }
    }
    return max;
}
TreeNode<int>* nextSmallerElement(TreeNode<int> *root, int n){
    // Write your code here
	if(root == NULL){
        return root;
    }

    TreeNode<int>* nextLarger = NULL;
    if(root -> data < n){
        nextLarger = root;
    }
   
    for(int i = 0; i < root-> numChildren(); i++){
        TreeNode<int>* temp = nextSmallerElement(root -> getChild(i), n);
        if(nextLarger == NULL){
            nextLarger = temp;
        }
        else if( temp!= NULL and temp -> data > nextLarger -> data){
            nextLarger = temp;
        }
    }
    return nextLarger;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }

    TreeNode<int>* max = maxDataNode(root);
    TreeNode<int>* max2 = nextSmallerElement(root, max -> data);
    
    return max2;
}

// Main Code:
/*
template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;

		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}

		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}

		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}

		~Queue() {
			delete [] data;
		}


};

#include <iostream>
#include <climits>
using namespace std;
TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();

		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {

			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL)
    	cout << INT_MIN << endl;
    else
	cout << ans -> data << endl;
}
*/