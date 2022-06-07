/*
CS-> https://www.codingninjas.com/codestudio/problems/1081470?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 62

Input Format: m = 2, n= 3 
Ouput: 3
    -> RRD
    -> RDR
    -> DRR

_____________________________________________________________________________
APPROACH -> RECURSION -> MEMOISATION -> TABULATION -> SPACE OPTIMISATION
_____________________________________________________________________________
Solution 3: Combinatorics Solution

Intuition: If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.

From start to reach the end we need a certain number of rightward directions and a certain number of downward directions. So we can figure out we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.

Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

Approach: 
    The approach of this solution is very simple just use a for loop to calculate 
    the m+n-2Cn-1  or m+n-2Cm-1 

    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solveRec(int row, int col){
    if(row == 0 && col == 0){
        return 1;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    int up = solveRec(row-1, col);
    int left = solveRec(row, col-1);
    
    return up + left;
}

int solveMem(int row, int col, vector<vector<int>> &dpMem){
    if(row == 0 && col == 0){
        return 1;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    if(dpMem[row][col] != -1) return dpMem[row][col];
    
    int up = solveMem(row-1, col, dpMem);
    int left = solveMem(row, col-1, dpMem);
    
    return dpMem[row][col] = up + left;
}

int solveTab(int m, int n){
    vector<vector<int>> dpTab(m, vector<int> (n, -1));
    dpTab[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0){
                dpTab[i][j] = 1;
            }
            else{
                int up = dpTab[i-1][j];
        	    int left = dpTab[i][j-1];
                dpTab[i][j] = up + left;
            }
        }
    }
    return dpTab[m-1][n-1];
}

int spaceOptimisation(int m, int n){
    // We only need prev row for (row-1) which we are using in dp[row-1]
    vector<int> prev(n, 0);		// prev row size will be-> number of columns (n)
    for(int i = 0; i<m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0){
                curr[j] = 1;
            }
            else {
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

int uniquePaths(int m, int n) {
// 	return solveRec(m-1, n-1);
    
//     vector<vector<int>> dpMem(m, vector<int> (n, -1));
//     return solveMem(m-1, n-1, dpMem);
    
//     return solveTab(m, n);
    
    return spaceOptimisation(m, n);
}