/*
CS-> https://www.codingninjas.com/codestudio/problems/759408?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 128

Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
-------------------------------------------------
Solution 1: (Brute force)
Approach: We can simply sort the array and run a for loop to find the longest consecutive sequence.
TC-> NlogN + N
SC-> 1
_________________________________________________________
Solution 2: (Optimal Approach)
Approach: 
    -> We will first push all are elements in the HashSet. 
    -> Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. 
    -> If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. 
    -> Using this we can calculate the length of the longest consecutive subsequence. 

TC-> N
SC-> N
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int longestConsecutive(vector<int>& nums) {
        
    // TC -> O(n) + O(n) + o(n) -> Inserting element in set, tranversal accros nums, traversal set
    // SC -> O(n)
    
    int n = nums.size();
    if(n < 2) return n;
    // put every element in the set
    unordered_set<int> st;
    for(int &a: nums) {
        st.insert(a);
    }
    
    int maxLen = 0, len = 0;
    
    for(int &num: nums) {
        // check if the (current Num - 1) is present in the set
        // (currentNum - 1) not present in the set
        // so num is the smallest number to start iteration for cons. seq.
        if(st.find(num - 1) == st.end()) {
            int currentNum = num;
            len = 1;
            
            while(st.find(currentNum + 1) != st.end()) {
                len += 1;
                currentNum += 1;
            }
            
            maxLen = max(maxLen, len);
        }
    }
    
    return maxLen;
}