/*
CS-> https://www.codingninjas.com/codestudio/problems/983605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC-> 18

Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
-----------------------------------------------
Solution 1: Sorting and then Using 3 pointers and Binary Search
Inutuition:
    [-2,-1, 0, 0,    1,   2]
    i    j  k {Binary search}

Approach:

    The main idea is to sort the array, and then we can think of searching in the array using the binary search technique. Since we need the 4 numbers which sum up to target. So we will fix three numbers as nums[i], nums[j] and nums[k], and search for the remaining (target – (nums[i] + nums[j] + nums[k])) in the array. Since we sorted the array during the start, we can apply binary search to search for this value, and if it occurs we can store them. In order to get the unique quads, we use a set data structure to store them.

Time Complexity: O(N log N + N³ logN) 
-> Sorting the array takes N log N and three nested loops will be taking N³ and for binary search, it takes another log N.
Sc-> O(M * 4), where M is the number of quads
___________________________________________________________________________
Solution 2: Optimized Approach (Sorting)
            2 for Loops and after 2 pointers

Intuition: 
    In the previous approach we fixed three-pointers and did a binary search to find the fourth. Over here we will fix two-pointers and then find the remaining two elements using two pointer technique as the array will be sorted at first.

Approach: 
    Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + nums[j])). Now we can fix two pointers, one front, and another back, and easily use a two-pointer to find the remaining two numbers of the quad. In order to avoid duplications, we jump the duplicates, because taking duplicates will result in repeating quads. We can easily jump duplicates, by skipping the same elements by running a loop.


*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Approach 1-> Sorting and then Using 3 pointers and Binary Search
/*
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    
    set<vector<int>> sv;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) { 
                
                int x = (long long)target -(long long)nums[i] - (long long)nums[j]-(long long)nums[k];
                
                if(binary_search(nums.begin()+k+1,nums.end(),x)){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(),v.end());
                    sv.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(sv.begin(),sv.end());
    return res;
}
*/

//  Approach -2
//

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n-3; i++) {
        for(int j = i+1; j < n-2; j++) {
            int target_2 = target - nums[i] - nums[j];
            
            int start = j+1;
            int end = n-1;
            
            while(start < end) {
                int two_sum = nums[start] + nums[end];
                
                if(two_sum == target_2) {
                    vector<int> v(4);
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[start];
                    v[3] = nums[end];
                    ans.push_back(v);
                    
                    while(start < end && nums[start] == v[2]) {
                        start++;
                    }
                    while(start < end && nums[end] == v[3]) {
                        end--;
                    }
                }
                else if(two_sum > target_2) {
                    end--;
                }
                else {
                    start++;
                }
            }
            
            while(nums[j] == nums[j+1] && j < n-2) {
                j++;
            }
        }
        while(nums[i] == nums[i+1] && i < n-3) {
            i++;
        }
    }
    return ans;
}