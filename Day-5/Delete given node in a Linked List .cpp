/*
CS-> https://www.codingninjas.com/codestudio/problems/1105578?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 237

Problem Statement: 
    Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

Examples:

Example 1:
Input Linked list: [1,4,2,3], Node = 2
Output: Linked list: [1,4,3]

Explanation: 
    Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].
--------------------------------------------------------------------

Approach:

    We are given access to nodes that we have to delete from the linked list. So, whatever operation we want to do in the linked list, we can operate in the right part of the linked list from the node to be deleted. 

    The approach is to copy the next node’s value in the deleted node. Then, link node to next of next node. This does not delete that node but indirectly it removes that node from the linked list.

Time Complexity: O(1)
Reason: It is a two-step process that can be obtained in constant time.

Space Complexity: O(1)
Reason: No extra data structure is used.
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


void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* todelete = node->next;
    node->next = node->next->next;
    delete todelete;
}