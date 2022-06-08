/*
CS-> https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

GFG-> https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result: 8

Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8
----------------------------------------------------
Solution 1 (Naive approach) :  Find all subarrays (2 for loops)
Intuition:

    We are required to find the longest subarray that sums to zero. So our initial approach could be to consider all possible subarrays of the given array and check for the subarrays that sum to zero. Among these valid subarrays (sum equal to zero) we’ll return the length of the largest subarray by maintaining a variable, say max.   

TC-> n^2
SC-> 1
________________________________________________________________
Solution 2 (Optimised Approach) :

-> Keep finding and storing prefix sum at each index
-> whenever the prefix sum becomes 0 -> This can be our possible ans
-> Whenever the prefix sum repeats 
-> it means that value betweeen curr index and already present prefix sum index is equal to 0

Intuition:  
    -> Now let’s say we know that the sum of subarray(i, j) = S, and we also know that sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.

    -> So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have same prefix sum, we can conclude that the 2nd part of this subarray sums to zero

Approach: 

First let us initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable say max = 0 which stores the length of longest subarray with sum zero.
Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
Now traverse the array, and add the array element to our sum. 
 (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      so we update max with the maximum value of (max, current_index+1)

(ii)  If sum is not equal to zero then we check hashmap if we’ve seen a subarray with this sum before

if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 

else -> Insert (sum, current_index) into hashmap to store prefix sum until current index

After traversing the entire array our max variable has the length of longest substring having sum equal to zero, so return max.

NOTE : we do not update the index of a sum if it’s seen again because we require the length of the longest subarray

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    // tc -> n * Logn -> n for traversal, logn for map
    // sc-> n
    
    int maxLen = 0;
    // prefix sum, index
    unordered_map<int,int> mp;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0) {
            maxLen = i+1;
        }
        else {
            // already prefix sum exist
            if(mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
    }
    return maxLen;
}