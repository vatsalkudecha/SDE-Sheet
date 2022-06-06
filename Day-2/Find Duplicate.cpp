/*
CS-> https://www.codingninjas.com/codestudio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC - 287

Input: arr=[1,3,4,2,2]

Output: 2

Explanation: Since 2 is the duplicate number the answer will be 2.

Optimal Solution: Using GAP Method (Image)

Intuition: 
    Since there is a duplicate number, we can always say that cycle will be formed.

    The slow pointer moves by one step and the fast pointer moves by 2 steps and there exists a cycle so the first collision is bound to happen.

    Let’s assume the distance between the first element and the first collision is a. So slow pointer has traveled a distance while fast(since moving 2 steps at a time) has traveled 2a distance. For slow and a fast pointer to collide 2a-a=a should be multiple of the length of cycle, Now we place a fast pointer to start. Assume the distance between the start and duplicate to be x. So now the distance between slow and duplicate shows also be x, as seen from the diagram, and so now fast and slow pointer both should move by one step.


*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findDuplicate(vector<int> &nums, int n){
    // solution-1 -> Using Sorting
    // solution-2 -> Using Frequency Array
    
    // Solution-2 -> Using GAP Method
    //TC - O(N). Since we traversed through the array only once.
	int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
