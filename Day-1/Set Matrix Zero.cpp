/*  Optimal 
    Intuition: 
        Instead of taking two dummy arrays we can use the first row and column of the matrix for the same work. This will help to reduce the space complexity of the problem. While traversing for the second time the first row and column will be computed first, which will affect the values of further elements that’s why we traversing in the reverse direction.

    Approach:
        Instead of taking two separate dummy array,take first row and column of the matrix as the array for checking whether the particular column or row has the value 0 or not.Since matrix[0][0] are overlapping.Therefore take separate variable col0(say) to check if the 0th column has 0 or not and use matrix[0][0] to check if the 0th row has 0 or not.Now traverse from last element to the first element and check if matrix[i][0]==0 || matrix[0][j]==0 and if true set matrix[i][j]=0,else continue.

        TC -> O(n*m + n*m)
        SC -> O(1)

        LC -> 73
        CS -> https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void setZ(int row, int col, int n, int m, vector<vector<int>> &v) {
        // row -> 0
        for(int j = 0; j<m; j++) {
            v[row][j] = 0;
        }

        // col -> 0
            for(int i = 0; i<n; i++) {
        v[i][col] = 0;
    }
}
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        // brute
        /*
        vector<vector<int>> v(n, vector<int> (m));
        
        v = matrix;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    setZ(i,j,n,m,v);
                }
            }
        }
        
        matrix = v;
        */
        
        // better -> using 1 dummy row, dummy col
        /*
        vector<int> row(n, -1), col(m, -1);
        
        for(int i=0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        */
        
        // -------------------------------------------
        // optimal -> instead of using dummy row, col 
        // -> make changes in the 1st row amd 1st col
        // -> arr[0][0] holds the val for row
        // col0 -> true/false hold the value for col
        
        
        
        int col0 = 1;
        
        for(int i = 0; i<n; i++) {
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
        
        
    }
};