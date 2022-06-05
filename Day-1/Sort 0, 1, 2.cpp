/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

CS -> https://www.codingninjas.com/codestudio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC -> 75

This problem is a variation of the popular Dutch National flag algorithm 

Intuition: 
    In this approach, we will be using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and hence the array will be sorted. 

Approach: 

    Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index

    int low = arr[0]

    int mid = arr[0]

    int high = arr[n – 1]

    Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

    arr[mid] == 0:
        swap(arr[low], arr[mid])
        low++, mid++

    arr[mid] == 1:
        mid++

    arr[mid] == 2:
        swap(arr[mid], arr[high])
        high--;

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void sort012(int *arr, int n)
{
	// simply sorting algo -> O(nlogn)
	
	// Better -> Counting Sort ->  O(n) + O(n)
	// count nos. of 0's, 1's and 2's
	
   // Optimal -> Dutch National Flag Algo O(n)
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}