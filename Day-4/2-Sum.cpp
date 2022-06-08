/*
CS-> https://www.codingninjas.com/codestudio/problems/pair-sum_697295?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC -> 1

Input Format: nums = [3,2,4,6], target = 6
Output: [1,2]
Explanation: Because nums[1] + nums[2] == 6, which is the required target, we return indexes [1,2].
----------------------------------------------

SOl-1 -> Brute force ->2 for loops
TC-> O(n^2)
_____________________________________________
Sol-2> Sortting and 2 pointer
TC-> nlogn
_______________________________________________
Solution 3: Hashing (Most efficient)

Approach: 
    -> We can solve this problem efficiently by using hashing. 
    -> We’ll use a hash-map to see if there’s a value (target – i) that can be added to the current array value i to get the sum equals to target. 
    -> If (target – i) is found in the map, we return the current index, 
    and index stored at (target – nums[index]) location in the map. 

    This can be done in constant time.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    int n = nums.size();
    map<int, int> m;
    for(int i =0; i<n; i++){
        if(m.find(target - nums[i]) == m.end()){
            m[nums[i]] = i;
        }
        else{
            
            v.push_back(m[target-nums[i]]);
            v.push_back(i);
        }
    }
    return v;
}