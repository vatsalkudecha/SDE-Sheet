/*
Input: [[1,2,3],
        [4,5,6],
        [7,8,9]]

Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

LC -> 48
CS -> https://www.codingninjas.com/codestudio/problems/rotate-matrix-by-90-degrees_981261

Intuition: 
    By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

Approach:

Step1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)
Step2: Reverse each row of the matrix.

TC ->  O(N*N) + O(N*N).One O(N*N) 
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void transpose(vector<vector<int>> &matrix, int n){
        
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    transpose(matrix, n);
    
    for(int i = 0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }    
}

//  IMPORTANT
// ------------------------------------------------------------

// Rotate ELEMENTS Clockwise
// CS: Important variation on CS
/*
https://www.codingninjas.com/codestudio/problems/981260?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

Input Matrix: [ [ 1, 2, 3 ] 
                [ 4, 5, 6 ] 
                [ 7, 8, 9 ] ]

Output Matrix: [ [ 4, 1, 2 ] 
                 [ 7, 5, 3 ] 
                 [ 8, 9, 6 ] ]

            
*/

#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0, col = 0;
    int prev, curr;
    int lastRow = n, lastCol = m;
    
    while(row < lastRow && col < lastCol) {
        
        if(row + 1 == lastRow || col + 1 == lastCol) {
            break;
        }
        
        prev = mat[row+1][col];
        // ------> left to right
        for(int i = col; i < lastCol; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;
        
        // right side (top - bottom)
        //    |
        //    |
        //    \/
        for(int i = row; i < lastRow; i++) {
            curr = mat[i][lastCol-1];
            mat[i][lastCol-1] = prev;
            prev = curr;
        }
        lastCol--;
        
        // <----------- bottom (right - left)

        for(int i = lastCol-1; i >= col; i--) {
            curr = mat[lastRow-1][i];
            mat[lastRow-1][i] = prev;
            prev = curr;
        }                  
        lastRow--;
        
        // left side (bottom - top)
        //    /\
        //     |
        //     |
        for(int i = lastRow-1; i >= row; i--) {
            curr = mat[i][col];
            mat[i][col] = prev;
            prev = curr;
        }  
        col++;
    }
}