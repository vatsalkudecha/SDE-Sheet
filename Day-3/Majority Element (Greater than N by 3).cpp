/*
CS-> https://www.codingninjas.com/codestudio/problems/893027?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC -> 229

Input:  N = 6, array[] = {11,33,33,11,33,11}

Output: 11 33

Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.
___________________________________________________________________________

// MOORE'S VOTING ALGO....
    // there can be only 2 majority elements
    
    -> num1 and num2 will store our currently most frequent and second most frequent element.
    -> c1 and c2 will store their frequency relatively to other numbers.
    
    -> We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition.

    -> Let, ele be the element present in the array at any index. 

    -> if ele == num1, so we increment c1.
    -> if ele == num2, so we increment c2.
    -> if c1 is 0, so we assign num1 = ele.
    -> if c2 is 0, so we assign num2 = ele.
    -> In all the other cases we decrease both c1 and c2.
    -> In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop check.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    
	int n = arr.size();
    vector<int> v;
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    for(int i = 0; i<n ; i++){
        if(arr[i] == num1){
            count1++;
        }
        else if(arr[i] == num2){
            count2++;
        }
        else if(count1 == 0){
            num1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = arr[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == num1){
            count1++;
        }
        else if(arr[i] == num2){
            count2++;
        }
    }
    if(count1 > n/3){
        v.push_back(num1);
    }
    if(count2 > n/3){
        v.push_back(num2);
    }
    return v;
}