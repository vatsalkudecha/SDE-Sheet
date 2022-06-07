/*
CS-> https://www.codingninjas.com/codestudio/problems/842495?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 169
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

Result: 2

Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.
______________________________________________________________
Moore’s Voting Algorithm

Intuition: 
    The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

Approach: 

-> Initialize 2 variables: 
    Count –  for tracking the count of element
    Element – for which element we are counting
-> Traverse through nums array.
    If Count is 0 then initialize the current traversing integer of array as Element 
    If the traversing integer of array and Element are same increase Count by 1
    If they are different decrease Count by 1
-> The integer present in Element is the result we are expecting 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    
//-------MEthod : 1-------- Storing entries occurences in map..
    // TC - n, SC- n
/*    unordered_map<int, int> m;
    
    for(auto a: nums)
    {
        m[a]++;
        if(m[a] > n/2)
        {
            return a;
        }
    }
    return -1;
    */
    
// ------Method : 2--------------- Sorting the array... max element entries begin from middle..So return mid element

    // TC - nlogn, SC - 1
/*
    sort(nums.begin(), nums.end());
    return nums[n/2];
*/
    
// ----Method:3--- Moore's Algorithm..COunting occurences..and if less than 0, thn change the candidate
    // TC - n, SC - 1 
    int candidate = 0, val = 0;
    
    for(auto a: nums)
    {
        if(val == 0)
        {
            candidate = a;
        }
        if(candidate == a)
        {
            val++;
        }
        else
        {
            val--;
        }
    }
    return candidate;        
}