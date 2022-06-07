/*
CS-> https://www.codingninjas.com/codestudio/problems/980531?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 74

Input: matrix = 
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]], 

target = 3

Output: true

Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.
---------------
Sol-1: Brute
___________________
Solution 2: [Efficient] – Binary search 
TC -> O(n * m)

Intuition: 
    As it is clearly mentioned that the given matrix will be row-wise and column-wise sorted, we can see that the elements in the matrix will be in a monotonically increasing order. So we can apply binary search to search the matrix. Consider the 2D matrix as a 1D matrix having indices from 0 to (m*n)-1 and apply binary search. Below the available image is the visual representation of the indices of 3*4 matrix.


Approach: 

    i) Initially have a low index as the first index of the considered 1D matrix(i.e: 0) and high index as the last index of the considered 1D matrix(i.e: (m*n)-1).

    ii) Now apply binary search. Run a while loop with the condition low<=high. Get the middle index as (low+high)/2.We can get the element at middle index using matrix[middle/m][middle%m].

    iii) If the element present at the middle index is greater than the target, then it is obvious that the target element will not exist beyond the middle index. So shrink the search space by 
    updating the high index to middle-1. 

    iv) If the middle index element is lesser than the target, shrink the search space by updating the low index to middle+1.

    v) If the middle index element is equal to the target integer, return true.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0) return 0;
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    int low = 0;
    int high = n*m -1;

    // Row -> mid / cols
    // Col -> mid % cols
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(matrix[mid / m][mid % m] == target){
            return true;
        }
        else if(matrix[mid / m][mid % m] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}