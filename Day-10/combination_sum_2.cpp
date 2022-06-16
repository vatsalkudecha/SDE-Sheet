// Leetcode: 40
// TC --> 2^t * k ---> 2 choices for every n elements and k time for putting the ds combination in vector
// SC --> exponential 

// only unique combination in each iteration...
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combination(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int target, int n)
    {
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i<n; i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            ds.push_back(candidates[i]);
            combination(i+1, ds, ans, candidates, target-candidates[i], n);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        combination(0, ds, ans, candidates,target, n);
        
        return ans;
    }
};