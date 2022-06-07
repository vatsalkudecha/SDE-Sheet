/*
CS-> https://www.codingninjas.com/codestudio/problems/1082146?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 50

Input: x = 2.00000, n = 10

Output: 1024.00000

Explanation: You need to calculate 2.00000 raised to 10 which gives ans 1024.00000
--------------------
sol-1 : Brute: Using For Loop
____________________________________________

Solution 2: Using Binary Exponentiation 
TC -> LogN

Approach: Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow

    Check if nn is a negative number, in that case, make it a positive number.

    Keep on iterating until nn is greater than zero, 
    -> now if nn is an odd power then multiply x with ans ans reduce nn by 1. 
    -> Else multiply x with itself and divide nn by two.

    Now after the entire binary exponentiation is complete and nn becomes zero, check if n is a negative value we know the answer will be 1 by and.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    if(x == 0){
        return (double) 0;
    }
    long long nn = n;
    if(nn < 0){
        nn = -1 * nn;
    }
    
    while(nn){
        if(nn % 2 == 1){
            ans = ans * x;
            nn = nn - 1;
        }
        else{
            x = x * x;
            nn /= 2;
        }
    }
    
    if(n < 0){
        ans = (double)(1.0)/(double)(ans);
    }
    return ans;
}