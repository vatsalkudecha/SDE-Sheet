/*
cs-> https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
gfg-> https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/
--------------------------------------------------------------
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

Examples:

Example 1:

Input: V = 70
Output: 2

Explaination: We need a 50 Rs note and a 20 Rs note.
________________________________________________________--
Solution: Greedy Algorithm

Approach: 
    We will keep a pointer at the end of the array i. 
    Now while(V >= coins[i]) we will reduce V by coins[i] and add it to the ans array.

    We will also ignore the coins which are greater than V and the coins which are less than V.
    We consider them and reduce the value of V by coins[I].

Time Complexity:O(V)
Space Complexity:O(1)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findMinimumCoins(int amount) 
{
    // Greedy approach below:
    /* This greedy approach will fail 
       When we add up two coin which will exceeds the other coin.
       Then try all possibilities -> Recursion
    */
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    int cnt = 0;
    sort(coins, coins + n);
    for(int i = n-1; i >= 0; i--) {
        if(coins[i] <= amount) {
            int val = amount/coins[i];
            amount = amount - val*coins[i];
            cnt += val;
        }
        if(amount == 0) {
            break;
        }
    }
    return cnt;
}
