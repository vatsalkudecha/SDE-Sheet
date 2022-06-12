/*
cs-> https://www.codingninjas.com/codestudio/problems/630519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 42
-----------------------------------------------------------
(Image)

Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped
___________________________________________________________
Solution 1: Brute force

Approach: 
    For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

Code:
int trap(vector < int > & arr) {
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0) {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n) {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}
Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.
________________________________________________________________-
Solution 2:Better solution

Intuition: 
    We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute the leftMax and rightMax at each index.

Approach:
    Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.
    Then use the formula min(prefix[i],suffix[i]) - arr[i] to compute water trapped at each index.

Time Complexity:O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.

Space Complexity:O(N)+O(N) for prefix and suffix arrays.
______________________________________________________________________
Solution 3:Optimal Solution(Two pointer approach)

Approach: 
    Take 2 pointer l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively.Take two variables leftMax and rightMax and initialise it to 0.If heigh[l] is less than or equal to height[r] then if leftMax is less then height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++.If height[r] is less then height[l],then now we are dealing with the right block.If height[r] is greater then rightMax,then update rightMax to height[r] else add rightMax-height[r] to the final answer.Now move r to the left. Repeat theses steps till l and r crosses each other.

Intuition: 
    We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, so we can surely say that there is a block with height more than height[l] to the right of l. And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height height[r]. So by traversing with these cases and using two pointers approach the time complexity can be decreased without using extra space.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Solution -2 

int trap(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;
    vector<int> maxleft(n);
    maxleft[0] = height[0];
    
    for(int i = 1; i<n; i++){
        maxleft[i] = max(maxleft[i-1], height[i]);
    }
    
    vector<int> maxright(n);
    maxright[n-1] = height[n-1];
    
    for(int i = n - 2; i >= 0 ; i--){
        maxright[i] = max(maxright[i+1], height[i]);
    }
    
    
    int totalWater = 0;
    vector<int> water(n);
    
    for(int i = 0; i<n; i++){
        water[i] = min(maxleft[i], maxright[i]) - height[i];
    }
    
    for(auto it: water){
        totalWater += it;
    }
    
    return totalWater;
}
// --------------------------------------------------

// solution - 3


int trap3(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}