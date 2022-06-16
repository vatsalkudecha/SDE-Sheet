/*
cs-> https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

lc-> 90

--------------------------------------------------------------------
Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Examples:

Example 1:

Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.
_____________________________________________
solution 1: Using Set 
___________________________________________________________

Solution 2: Optimal

Approach: 
    -> Sort the input array.Make a recursive function that takes the input array ,the current subset,the current index and  a list of list/ vector of vectors to contain the answer.
    -> Try to make a subset of size n during the nth recursion call and consider elements from every index while generating the combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.
    -> Once an element is picked up, move to the next index.The recursion will terminate when the end of array is reached.While returning backtrack by removing the last element that was inserted.

Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void subsets(int ind, vector<int> &v, vector<vector<int>> &ans, vector<int>& nums, int n){
        ans.push_back(v);
        for(int i = ind; i < n; i++){
            if(i!=ind && nums[i] == nums[i-1]) 
                continue;
            v.push_back(nums[i]);
            subsets(i+1, v, ans, nums, n);
            v.pop_back();
        }
    }
                
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        subsets(0, v, ans, nums, n);
        return ans;
    }
};