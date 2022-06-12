/*
lc -> 485
----------------------------
Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.
-______________________________________________
Solution:

    We start traversing from the beginning of the array. Since we can encounter either a 1 or 0 there can be two situations:-

        -> If  the value at the current index is equal to 1 we increase the value of count by one. -> -> After updating  the count variable if it becomes more than the max_count  update the max_count.
        -> If the value at the current index is equal to zero we make the variable count as 0 since there are no more consecutive ones.

TC -> O(N)

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, count = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        
        if(nums[i] == 1){
            count++;
        }
        else{
            count = 0;
        }
        res = max(res, count);
    }
    return res;
}