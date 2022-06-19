/*
cs-> https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Interviewbit -> https://www.interviewbit.com/problems/matrix-median/
-----------------------------------------------------------------------

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.
________________________________________________________________________
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//BRUTE 
int brute(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<int> v;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            v.push_back(A[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return (v[n*m/2]);
}


int countSmallerThanEqualMid(vector<int> &row, int mid) {
    int low = 0, high = row.size() - 1;
    int md;
    
    while(low <= high) {
        md = (low + high) >> 1;
        if(row[md] <= mid) {
            low = md + 1;
        }
        else {
            high = md - 1;
        }
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 1, high = 1e9, mid;
    
    while(low <= high) {
        mid = (low + high) >> 1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += countSmallerThanEqualMid(matrix[i], mid);
        }
        if(count <= (n*m)/2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}