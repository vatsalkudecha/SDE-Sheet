/*
cs-> https://www.codingninjas.com/codestudio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
Lc-> 46
--------------------------------------------
Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]
_______________________________________________-

*/

#include<bits/stdc++.h>
using namespace std;

// approach - 1: Using extra space for marking visiting index and putting that index in our ds. After rec call, unmark the index and pop element from ds
// TC -> n! * n
// SC -> O(n) + O(n)
class Solution
{
private:
    void solve1(vector<int> &v, vector<vector<int>> &ans, vector<int>&nums, vector<int> &vis, int n){
            if(v.size() == n){
                ans.push_back(v);
                return;
            }
            for(int i = 0; i<n; i++){
                if(vis[i] != 0){            
                    continue;
                }
                vis[i] = 1;
                v.push_back(nums[i]);
                solve1(v, ans, nums, vis, n);
                vis[i] = 0;
                v.pop_back();
            }
        }

// Approach 2: Swapping curr index with other index on its right
// TC - O(n!) * n
// SC - O(1)
    void solve2(int ind, vector<vector<int>> &ans, vector<int>&nums, int n){
        if(ind == n){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i<n; i++){
            swap(nums[ind], nums[i]);
            solve2(ind+1, ans, nums, n);
            swap(nums[ind], nums[i]);
        }        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> vis(n, 0);
        solve1(v, ans, nums, vis, n);
        solve2(0, ans, nums, n);
        return ans;
    }
};