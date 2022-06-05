/*
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples:

Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
---------------------
Solution 1: Brute Force (Image : 1)

Intuition: 
    We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

Approach: 

    Use a for loop of ‘i’ from 0 to n.
    Use another for loop from ‘i+1’ to n.
    If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
    Return maxPro.
------------------------

Soltuion 2:Optimal solution (Image -2)

Intuition: 
    We will linearly travel the array. We can maintain a minimum from the starting of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

Approach:

    -> Create a variable maxPro and mark it as 0.
    -> Create a variable minPrice and mark it as max_value.
    -> Run a for loop from 0 to n.
    -> Update the minPrice if it greater than current element of the array
    -> Take the difference of the minPrice with the current element of the array and compare and    maintain it in maxPro.
    -> Return the maxPro.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumProfit(vector<int> &prices){
	int n = prices.size();
	int mx = 0;
	int min_price_now = 1e9;
	for(int i = 0; i < n; i++) {
		if(min_price_now > prices[i]){
			min_price_now = prices[i];
		}
		mx = max(mx, prices[i] - min_price_now);
	}
	return mx;
}