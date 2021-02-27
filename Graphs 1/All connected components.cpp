/* Problem: All connected components
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

// Solution:
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int> oneComponent(int** edges, int sv, int n, bool* visited){
    vector<int> component;
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int cur = pendingVertices.front();
        pendingVertices.pop();
        component.push_back(cur);
        for(int i = 0; i < n; i++){
            if(edges[cur][i] == 1 and !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return component;
}
vector<vector<int>> allConnectedComponents(int** edges, int n){
    vector<vector<int>> res;
  	bool* visited = new bool[n];

    for(int i = 0; i < n; i++){
        if(!visited[i]){
    	    vector<int> component = oneComponent(edges, i, n, visited);
	        res.push_back(component);            
        }
    }
 	delete[] visited;
    return res;
}
int main(){
    int n, e;
    cin >> n >> e;
  	int** edges = new int*[n];
  	for(int i = 0; i < n; i++){
    	edges[i] = new int[n];
    	for(int j = 0; j < n; j++){
      		edges[i][j] = 0;
    	}
  	}

  	for(int i = 0; i < e; i++){
    	int f, s;
    	cin >> f >> s;
    	edges[f][s] = 1;
    	edges[s][f] = 1;
  	}
	
    vector<vector<int>> output = allConnectedComponents(edges, n);
    for(int i = 0; i < output.size(); i++){
        sort(output[i].begin(), output[i].end());
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;
    return 0;
}