/* Code : Sudoku
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

// Solution:
bool isRowSafe(int board[][9], int row, int num)
{
    for(int j = 0;j < 9; j++){
        if(board[row][j] == num){
            return false;
        }
    }
    return true;
}
bool isColSafe(int board[][9], int col, int num){
    for(int i = 0; i < 9;i++){
        if(board[i][col] == num){
            return false;
        }
    }
    return true;
}
bool isBoxSafe(int board[][9], int row, int col, int num){    
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    
    for(int i = rowStart; i < rowStart + 3; i++){
        for(int j = colStart; j < colStart+3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}
bool canPlaceNum(int board[][9], int row, int col, int num){
    if(!isRowSafe(board, row, num)){
        return false;
    }
    if(!isColSafe(board, col, num)){
        return false;
    }
    if(!isBoxSafe(board, row, col, num)){
        return false;
    }
    return true;
}
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){    
                isEmpty = true;
                row = i;
                col = j;
                break;
            }
        }
        if(isEmpty){
            break;
        }
    }
    if(!isEmpty){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(canPlaceNum(board, row, col, num)){
            board[row][col] = num;
            if(sudokuSolver(board)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

// Main Code:
/*
#include<iostream>
using namespace std;
int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}
*/