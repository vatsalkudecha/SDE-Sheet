/*
cs-> https://www.codingninjas.com/codestudio/problems/759332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

LC-> 51
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, int n, vector<string> &board){
        int r = row, c = col;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;c--;
        }
        r = row, c = col;
        while(c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            c--;
        }
        r = row, c = col;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;c--;
        }
        return true;
    }
    
    void solve1(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, n, board)){
                // this function is gonna take 3 -> O(n) tc for checking if the queen is safe or not
                board[row][col] = 'Q';
                solve1(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    // 
    void solve2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            // left row -> mark visited when if that place already contains queen
            // upper diagonal -> array of size 2n-1, value 1 if the upper diag has queen
            // lower diagnal -> array of size 2n-1, value 1 if the lower diag has queen
            if(leftRow[row] == 0 && upperDiagonal[col-row + n-1] == 0 && lowerDiagonal[row + col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[col-row + n-1] = 1;
                lowerDiagonal[row + col] = 1;
                solve2(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row]= 0;
                upperDiagonal[col-row + n-1] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);    
        /*
        board -> [-, -, -, -]
        */
       // string s is "...." for n = 4
        string s(n, '.');   
        // this is basically putting string s in string vector  (board)
        for(int i = 0; i<n; i++){
            board[i] = s;
        }

        /*
        board -> [
            "....",
            "....",
            "....",
            "...."            
        ]
        */

        //  (col, board, ans)
        // solve1(0, board, ans, n);
        
        vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n-1, 0);

        // tc optimization function
        solve2(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};