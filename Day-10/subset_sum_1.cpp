/*
cs-> https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

gfg-> https://practice.geeksforgeeks.org/problems/subset-sums2234/1
--------------------------------------------------------
Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

______________________________________________________________
Solution 1: Using recursion

Intuition: 
    The main idea is that on every index you have two options either to select the element to add it to your subset(pick) or not select the element at that index and move to the next index(non-pick).

Approach: 
    Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findSubsetSum(int ind, int sum, vector<int> &v, vector<int> &arr, int n){
        if(ind == n){
            v.push_back(sum);
            return;
        }
        sum += arr[ind];
        findSubsetSum(ind+1, sum, v, arr, n);
        sum -= arr[ind];
        findSubsetSum(ind+1, sum, v, arr, n);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        findSubsetSum(0, 0, v, arr, N);
        sort(v.begin(), v.end());
        return v;
    }
};