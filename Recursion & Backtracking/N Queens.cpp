/* Code: N Queens
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

// Solution:
#include <iostream>
using namespace std;
bool isSafe(int row, int col, int n, int board[][10]){  
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1){
            return false;
        }
    }
    int i = row;
    int j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    
    i = row;
    j = col;
    while(i >= 0 && j < n){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void placeQueen(int row, int n, int board[][10]){
  
    if(row == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] <<" ";
            }
        }
        cout << endl;
        return;
    }
  
    for(int i = 0; i < n ; i++) {
        if(isSafe(row, i, n, board)){
            board[row][i] = 1;  
            placeQueen(row + 1, n, board); 
            board[row][i] = 0;
        }
    }
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int board[10][10] = {};
	placeQueen(0, n, board);

}

// Main Code:
/*
#include<iostream>
using namespace std;
int main(){
  int n; 
  cin >> n ;
  placeNQueens(n);
}
*/