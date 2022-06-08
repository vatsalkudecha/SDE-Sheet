/*
CS-> https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Input Format:  A = [4, 2, 2, 6, 4] , B = 6
Result: 4
Explanation: The subarrays having XOR of their elements as 6 are:
             [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
------------------------------------------------------------------------
Solution 1: Brute Force-> generate all possible subarrays.             
2 For Loops
TC-> N^2
SC-> 1
____________________________________________________
Solution 2: Prefix xor and map (image)

Intuition: 
    The main idea is to observe the prefix xor of the array. Prefix Xor is just another array, where each index contains XOR of all elements of the original array starting from index 0 up to that index. In other words:

    prefix_xor[i] = XOR(a[0], a[1], a[2],……,a[I])

Once we have made the prefix xor array, we observe a fact:

P = xor(a[0], a[1], a[2],……, a[q], a[q+1],….., a[p])
Q = xor(a[0], a[1], a[2],……, a[q])

Therefore,
P^Q = xor(a[q+1],….., a[p]) = M                                
So, now we understand that from the prefix xor array when we XOR two elements at different indices we get the xor of the elements (in the original array) that were between those indices.
Let’s say we did XOR(P, B) and we got Q (B is the integer given in question). What does this mean?
This means that the subarray between q and p is having xor = B. To understand this we just use simple equations:
P^B = Q
=> B = Q^P  

And we already know by fact 1 that Q^P will give xor of all elements between q and p. Therefore, the subarray between q and p has xor = B.
Suppose we did XOR(P, B) and we got Q (B is the integer given in question). But there is more than one Q before p.

In this case, there are two subarrays that have XOR = B. Subarrays between q1 to p and q2 to p. 

IMP NOTE: although we talk about prefix xor “array”, it should be noted that at a time we need only one element of this array. Hence, we can just use a variable to maintain the prefix xor. 

Approach: 
    -> We need to traverse the array while we maintain variables for current_perfix_xor, counter, and also a map to keep track of visited xors. 
    -> This map will maintain the frequency count of all previous visited current_prefix_xor values. -> If for any index current_prefix_xor is equal to B, we increment the counter. 
    -> If for any index we find that Z is present in the visited map, we increment the counter by visited[Z] (Z=current_prefi_xor^B). 
    -> At every index, we insert the current_prefix_xor into the visited map with its frequency.

Time Complexity: O(N)
Space Complexity: O(N)

NOTE: the complexity of worst-case searching for an unordered_map can go up to O(N), hence it is safer to use ordered_map. But if we use ordered_map then the time complexity will be O(N logN). Space complexity will be the same in both cases.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    // brute 
    // tc -> n^2
    /*
    int cnt = 0;
    int n = arr.size();
    int xorr = 0;
    for(int i = 0; i < n; i++) {
        xorr = 0;
        for(int j = i; j < n; j++) {
            xorr ^= arr[j];
            if(xorr == x) cnt++;
        }
    }
    return cnt;
    */
    
    // prefix xorr, count(this prefix xor has occurred)
    map<int, int> mp;
    int cnt = 0;
    int xorr = 0;
    for(int &a: arr) {
        xorr = xorr ^ a;
        
        if(xorr == x) {
            cnt++;
        }
        // mp[xorr^x]-> that many subarray with this values has formed
        if(mp.find(xorr ^ x) != mp.end()) {
            cnt += mp[xorr ^ x];
        }
        mp[xorr]++;
    }
    return cnt;
}