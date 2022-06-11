/*
CS-> https://www.codingninjas.com/codestudio/problems/920454?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
LC-> 61
-------------------------------------
Input:
	head = [1,2,3,4,5] 
	k = 2
Output:
    head = [4,5,1,2,3]
Explanation:
    We have to rotate the list to the right twice.
----------------------------------------------------------------
Solution: Brute Force

Approach:

    We have to move the last element to first for each k.

    For each k, find the last element from the list. Move it to the first.

Time Complexity: O(nodes * k)
Reason: For k times, we are iterating through the entire list to get the last element and move it to first.

Space Complexity: O(1)
_______________________________________________________________________
Solution: Optimal Solution

Approach:

    Let’s take an example. 

    head = [1,2,3,4,5] k = 2000000000

    -> If we see brute force approach, it will take O(5*2000000000) which is not a good time complexity when we can optimize it.

    -> We can see that for every k which is multiple of the length of the list, we get back the original list. Try to operate brute force on any linked list for k as multiple of the length of the list.

    -> This gives us a hint that for k greater than the length of the list, we have to rotate the list for k % length of the list. This reduces our time complexity.

    -> Steps to the algorithm:-

        -> Calculate length of the list
        -> Connect the last node to the first node, converting it to a circular linked list.
        -> Iterate to cut the link of the last node and start a node of k % length of list rotated list.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    // edge case
    if(head==NULL || head->next==NULL || k==0) return head;
    
    // compute the length
    int len = 1;
    
    ListNode* curr = head;
    
    while(curr->next != NULL) {
        len++;
        curr = curr->next;
    }
    
    // join the end node with head node
    
    curr->next = head;
    
    // update k
    k = k % len;
    k = len - k;
    
    // If len = 5, curr is at end node 5 & need to reach 3 to make its next null
    // move (len - k) times
    
    while(k--) {
        curr = curr->next;
    }
    
    // make the next node head and break connection
    head = curr->next;
    curr->next = NULL;
    
    return head;
}