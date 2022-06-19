/*
cs-> https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
-----------------------------------------
Input: N=3 M=27

Output: 3

Explanation: The cube root of 27 is 3.
_______________________________________________________________________
Solution:

    Nth root of a number M is defined as a number X when raised to the power N equals to M.

Approach: 
    In order to find the Nth root of any given integer we are gonna use Binary Search.

    Step 1: Take low and high. Low will be equal to 1 and high will be M. We will take the mid of low and high such that the searching space is reduced using low + high / 2.

    Step 2: Make a separate function to multiply mid N times.

    Step 3: Run the while loop till (high – low > eps). Take eps as 1e-6, since we have to find answers to 6 decimal places.

    Step 4:  If the mid is less than M, then we will reduce search space to low and mid. Else, if it is greater than M then search space will be reduced to mid and high.

    Step 5: After the loop breaks we will have our answer as low or high.

    We have to find the answer to 5 decimals. So, we will have a double 1e-6. We will run the while loop till (high – low > eps). When we will come out of the loop we will have the answer which will be equal to low as well as high.

Time Complexity: N x log(M x 10^d) -> d (decimal places for precision)

Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

double multiply(double number, int n) {
    double ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = ans * number;
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
    double low = 1, high = m, mid;
    double eps = 1e-7;
    
    while((high - low) > eps) {
        mid = (high + low)/2.0;
        if(multiply(mid, n)*1LL < m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
//     cout << setprecision(10) <<" " << low;
    return low;
    
    
    // Above code not giving correct ans (correct logic)
    return (double)pow(m, 1.0/n);
}
