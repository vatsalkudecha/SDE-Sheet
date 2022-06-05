/*

Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

CS -> https://www.codingninjas.com/codestudio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

LC -> 31

Brute Force: Finding all possible permutations. 

    Approach :

    Step 1: Find all possible permutations of elements present and store them.

    Step 2: Search input from all possible permutations.

    Step 3: Print the next permutation present right after it.

    For reference of how to find all possible permutations, follow up https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s. This video shows for distinct elements but code works for duplicates too.

    TC ->  N!xN

Better: Using in-built function next_permutation() 

Optimal:

    Intuition :

    Intuition lies behind the lexicographical ordering of all possible permutations of a given array. There will always be an increasing sequence of all possible permutations when observed.

    Thus, we can see every sequence has increasing order. Hence, our approach aims to get a peak from where the increasing sequence starts. This is what we achieve from our first step of the approach. 

    Then, we need to get just a larger value than the point where the peak occurs. To make rank as few as possible but greater than input array, just perverse array from breakpoint achieved from the first step of the approach. We achieve these from all remaining steps of our approach.

    Approach :

    Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. Store that index in a variable.

    Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. Linearly traverse array from backward. Find an index that has a value greater than the previously found index. Store index another variable.

    Step 3: Swap values present in indices found in the above two steps.

    Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.

    TC-> 3*O(N)
    SC - 1
*/


#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> nextPermutation(vector<int> &nums, int n)
{
    int ind1 = -1, ind2 = -1;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            ind1 = i;
            break;
        }
    }
    if(ind1 < 0) {
        reverse(nums.begin(), nums.end());
        return nums;
    }
    else {
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] > nums[ind1]) {
                ind2 = i;
                break;
            } 
        }
        swap(nums[ind1], nums[ind2]);
        reverse(nums.begin() + ind1 + 1, nums.end());
        return nums;
    }
}