/*
Example 1:

Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 

Output: 6 

Explanation: [4,-1,2,1] has the largest sum = 6. 

CS -> https://www.codingninjas.com/codestudio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

LC -> 53

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long maxSubarraySum(int nums[], int n)
{
    // n^3 solution
    /*
        int maxi = -1e8;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int sum = 0;
                for(int k = i; k<= j; k++) {
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
        */

    // n^2 soln
    /*
        int maxi = -1e8;
        for(int i = 0; i<n; i++) {
            int sum = 0;
            for(int j = i; j<n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }            
        }
        return maxi;
        */

    // O(n) -> Kadane's Algo

    long long maxi = nums[0];
    long long sum = 0;

    for(int i = 0; i<n; i++) {
        sum += nums[i];
        if(sum < 0) {
            sum = 0; 
        }
        maxi = max(maxi, sum);
    }
    return maxi;
    
}