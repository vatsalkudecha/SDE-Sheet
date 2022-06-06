/*
CS-> https://www.codingninjas.com/codestudio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC - 88

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]
------------------------
Solution1: Brute Force-

Intuition: We can use a new array of size n+m and put all elements of arr1 and arr2 in it, and sort it. After sorting it, but all the elements in arr1 and arr2.
--------------------------------
Solution 2: Without using space-
Intuition: 
    We can think of Iterating in arr1 and whenever we encounter an element that is greater than the first element of arr2, just swap it. Now rearrange the arr2 in a sorted manner, after completion of the loop we will get elements of both the arrays in non-decreasing order.

Approach:

-> Use a for loop in arr1.
-> Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
-> Rearrange arr2.
-> Repeat the process.
----------------------------------
Solution 3: Gap method (Image)

Approach:
    Initially take the gap as (m+n)/2;
    Take as a pointer1 = 0 and pointer2 = gap.
    Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
    After completion of the loop reduce the gap as gap=gap/2.
    Repeat the process until gap>0.

TC -> O(logn)
Sc -> O(1)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, k = m+n-1;
    
    while( i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;k--;
        }
        else{
            nums1[k] = nums2[j];
            j--;k--;
        }
        
    }     
    while(i >= 0){
        nums1[k] = nums1[i];
        i--;k--;
    }
    while(j >= 0){
        nums1[k] = nums2[j];
        j--;k--;
    }
}