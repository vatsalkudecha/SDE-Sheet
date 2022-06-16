/*
cs-> https://www.codingninjas.com/codestudio/problems/759331?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

arr: [2 4 6]
target: 6

Output:
    For the array'ARR' = {2, 4, 6}, we can have subsets {}, {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}. Out of these 8 subsets, {2, 4} and {6} sum to the given 'K' i.e. 6. 
*/

// Leetcode: 39
// TC --> 2^t * k ---> 2 choices for every n elements and k time for putting the ds combination in vector
// SC --> exponential 

/*
For negative Inputs
Code:
    void fun(vector<int> &arr,int n,int i,int k, vector<int> &v,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(v);
        }
        if(i>=n) return ;

        for(;i<n;i++){
            v.push_back(arr[i]);
            fun(arr,n,i+1,k-arr[i],v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        fun(arr,n,0,k,v,ans);  
        return ans;
    }
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combination(int ind, int sum, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int n, int target)
    {
        if(ind == n){
            if(sum == target){
                ans.push_back(ds);
            }
            return;
        }
        // pick
        if(sum + candidates[ind] <= target){
            sum += candidates[ind];
            ds.push_back(candidates[ind]);
            combination(ind, sum, ds, ans, candidates, n, target);

            sum -= candidates[ind];
            ds.pop_back();
        }
        
        // non-pick
        combination(ind+1, sum, ds, ans, candidates, n, target);
    }        

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        int sum = 0;
        combination(0, sum, ds, ans, candidates, n, target);
        return ans;
    }
};