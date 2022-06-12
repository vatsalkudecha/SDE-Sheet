/*
cs-> https://www.codingninjas.com/codestudio/problems/893028?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
lc-> 15
----------------------------------------
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k
_____________________________________________________________
Solution 1 (Brute Force): (3 for loops)
Approach: 
    We keep three-pointers i,j, and k. For every triplet we find the sum of A[i]+A[j]+A[k]. If this sum is equal to zero, we’ve found one of the triplets. We add it to our data structure and continue with the rest.

Time Complexity : O(n^3)   // 3 loops
Space Complexity : O(3*k)  // k is the no.of triplets
____________________________________________________________________
Solution 2 (Optimized Approach): (fix i, and then 2 pointer approach)

Approach:
    We could make use of the fact that we just need to return the triplets and thus could possibly sort the array. This would help us use a modified two-pointer approach to this problem.

    Eg) Input :  [-1,0,1,2,-1,-4]

    After sorting, our array is : [-4,-1,-1,0,1,2]

    -> Notice, we are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the sum of three numbers equals zero. 
    -> If the sum is less than zero, it indicates our sum is probably too less and we need to increment our j pointer to get a larger sum. 
    -> On the other hand, if our sum is more than zero, it indicates our sum is probably too large and we need to decrement the k pointer to reduce the sum and bring it closer to zero.

Time Complexity : O(n^2)  

Space Complexity : O(M). 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        
    int n = nums.size();
    if(n < 3) return {};
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> res;
    
    //moves for a
    for(int i = 0; i < n - 2; i++){
        
        if(i == 0 || (i > 0  && nums[i] != nums[i-1])){
            
            int low = i+1, high = nums.size()-1;
            int sum = 0 - nums[i];
            
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    
                    res.push_back(temp);
                    
                    while(low < high && nums[low] == nums[low + 1]){
                        low++;
                    }
                    while(low < high && nums[high] == nums[high - 1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
    }
    return res;
}