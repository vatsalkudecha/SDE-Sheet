/*
CS-> https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 8

Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
    (3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and 
    (1,4) as both are not satisfy our condition. 
________________________________________________
Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: 
    we have a reverse sorted array and we will 
    get the maximum inversions as for i < j we will always 
    find a pair such that A[j] < A[i]. 
    Example: 5 has index 0 and 3 has index 2 now (5,3) pair 
    is inversion as 0 < 2 and 5 > 3 which will satisfy out 
    conditions and for reverse sorted array we will get 
    maximum inversions and that is (n)*(n-1) / 2.

    For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
___________________________________________
Intution: 
    If an array is sorted, the array inversions are 0, and if reverse sorted, the array inversions are maximum.
-------------------------------------
Solution-1:  two nested loops
------------------------------------
Solution-2:  (Image)
    To sort the array, we will use mergeSort. In mergeSort, we will deep in one element, compare two elements, and put it in a new array in sorted order. By doing this for log(N) time, we will get the sorted array, and while comparing the two array elements, we will add some more lines of code such that it will count the inversion of the smaller array and slowly it will count for larger and larger array.

Approach: 

    Let’s understand the algorithm by example. We slice the array in the middle and further slice it in merge sort, as shown in the figure.

    The single element is always sorted after slicing to the bottom and getting them on an element as an array. Before returning the merged array with sorted numbers, we will count the inversion from there. How?

    1st condition i < j above in the image, you can see that the right element’s index is always greater, so while computing the inversion, we should take care only 2nd condition, which is if i < j then A[j] < A[i] to make a pair and add one to the count.

    In the above example i < j as i is the 5’s index and j is 3’s index and (A[i] == 5) > (A[j] == 3) so we got our first inversion pair (5,3) after that merge then into one array [3,5] and return it for further computations now lets take another example:

    [2,3,5] and [1,4] and count = 3. How to calculate it further? 

    Compare elements in 1st array with the 2nd array’s all elements if 1’s array’s element is greater than 2’s array then we will count it as inversion pair as 1st condition for inversion will always satisfy with right arrays. 2 > [1], 3 > [1], 5 > [1,4] so we will get 4 inversion pairs from this. and total inversion pair from [5,3,2,1,4] is 7.

    Dry Run: I have explained the main dry run case above, and for a full dry run, I have added this image:
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long merge(long long arr[], long long low, long long mid, long long high) {
    long long n1 = mid - low + 1;
    long long n2 = high - mid;

    long long right[n1], left[n2];

    for(long long i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }

    for(long long i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    long long i = 0, j = 0, k = low;
    long long res = 0;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while(i < n1)
    {
        arr[k++] = left[i++];
    }

    while(j < n2)
    {
        arr[k++] = right[j++];
    }

    return res;
}

long long mergeSort(long long arr[], long long low, long long high)
{
    long long res = 0;

    if(low < high)
    {
        long long mid = low + (high - low)/2;

        res += mergeSort(arr, low, mid);
        res += mergeSort(arr, mid + 1, high);

        res += merge(arr, low, mid, high);
    }

    return res;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}