/*
cs-> https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
gfg-> https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
--------------------------------------------------

Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00
-----------------------------------------------------------------
Solution: Greedy

Approach: 

    -> The greedy method to maximize our answer will be to pick up the items with higher values. -> -> Since it is possible to break the items as well we should focus on picking up items having higher (value/weight) first. 
    -> To achieve this, items should be sorted in decreasing order with respect to their 
    (value/weight). 
    -> Once the items are sorted we can iterate. 
    -> Pick up items with weight lesser than or equal to the current capacity of the knapsack. 
    -> In the end, if the weight of an item becomes more than what we can carry, break the item into smaller units. 
    -> Calculate its value according to our current capacity and add this new value to our answer.

Time Complexity: O(n log n + n). 
    O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

Space Complexity: O(1),
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool comparator(Item a, Item b) {
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    
    if(r1 > r2) {
        return true;
    }
    else {
        return false;
    }
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comparator);

    int curWeight = 0;
    double finalValue = 0.0;
    
    for(int i = 0; i < n; i++) {
        // if curr element is fitting completelu inside the knapsack -> take it
        if(curWeight + arr[i].weight <= W) {
            finalValue += arr[i].value;
            curWeight += arr[i].weight;
        }
        else {
            int remain = W - curWeight;
                            // value/wight * remaining
            finalValue += (arr[i].value/(double)arr[i].weight) * (double)remain;
            break;
        }
    }
    return finalValue;
}