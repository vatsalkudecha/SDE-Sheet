/*
CS -> https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

Input Format: array[] = {3,1,2,5,4,6,7,5}

Result: {5,8)

Explanation: A = 5 , B = 8 
            Since 5 is appearing twice and 8 is missing 

________________
sol-1: SC - O(n) 
    Using Freq vector
___________________
sol-2: Using math (Code given in function)
    Intuition + Approach: 

    The idea is to convert the given problem into mathematical equations. Since we have two variables where one is missing and one is repeating, can we form two linear equations and then solve for the values of these two variables using the equations?
    Let’s see how.

    Assume the missing number to be X and the repeating one to be Y.

    Now since the numbers are from 1 to N in the array arr[]. Let’s calculate sum of all integers from 1 to N and sum of squares of all integers from 1 to N. These can easily be done using mathematical formulae.

    Therefore,

    Sum of all elements from 1 to N:

    S = N*(N+1)/2 ---- equation 1
    And, Sum of squares of all elements from 1 to N:

    P = N(N+1)(2N+1)/6. ----- equation 2
    Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

    s1 = Sum of all elements of the array. —– equation 3
    P1 = Sum of squares of all elements of the array. ——– equation 4
    Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

    Therefore,

    (X-Y) = s – s1 = s’

    Similarily,

    X^2 – Y^2 = P – P1 = P’

    or, (X + Y)(X – Y) = P’

    or, (X + Y)*s’ = P’

    or, X + Y = P’/s’

    Great,

    we have the two equations we needed:

    (X – Y) = s’

    (X + Y) = P’/s’

    We can use the two equations to solve and find values for X and Y respectively.

    Note: here s and P can be large so take long long int data type.
_______________________________________
Sol - 3: Code 
*/
    

#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
    
    // sol-2: Using math
    /*
    long long int S = (n * (n+1) ) /2;
    long long int P = (n * (n +1) *(2*n +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i = 0; i < n; i++){
       S -= (long long int) arr[i];
       P -= (long long int) arr[i]*(long long int) arr[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    pair<int,int> p;
    p.first = missingNumber;
    p.second = repeating;

    return p;
    */
    
    // Sol-3: Using XOR
//     Not very intuitive
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {x, y};
    
    return {y, x};
}
