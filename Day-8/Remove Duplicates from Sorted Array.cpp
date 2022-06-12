/*
cs-> https://www.codingninjas.com/codestudio/problems/1102307?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
lc-> 26
-----------------------------
Input: arr[1,1,2,2,2,3,3]

Output: 3, arr[1,2,3,_,_,_,_]

Explanation: Total number of unique elements are 3, i.e[1,2,3] 
            Therefore return 3 after assigning [1,2,3] in the beginning of the array.
-----------------------------------------------
Solution 1: Brute Force: Using Hashset

Time complexity: O(n*log(n))+O(n)
Space Complexity: O(n) 
-------------------------------------------------
Solution 2: Two pointers (Image)

Intuition: 
    We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j]. 

Approach:

    Take a variable i as 0;
    Use a for loop by using a variable ‘j’ from 1 to length of the array.
    If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
    After completion of the loop return i+1, i.e size of the array of unique elements.

Time complexity: O(n)

Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int removeDuplicates(vector<int> &nums, int n) {
    int i = 0, j = 1, k = 1;
    if(n == 0) return 0;
    while(i < n - 1){
        if(nums[i] != nums[j]){
            nums[k] = nums[j];
            k++;i++; j++;
        }
        else if(nums[i] == nums[j]){
            i++; j++;
        }
    }
    return k;
}