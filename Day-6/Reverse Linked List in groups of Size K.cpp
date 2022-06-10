/*
CS-> https://www.codingninjas.com/codestudio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 25
-----------------------
Input:
 head = [1,2,3,4,5,6,7,8] k=3
Output:
 head = [3,2,1,6,5,4,7,8]
 ______________________________________________________
Solution:

Approach:

    The following steps are needed to arrive at the desired output. 

    -> Create a dummy node. Point next to this node to head of the linked list provided.
    -> Iterate through the given linked list to get the length of the list.
    -> Create three pointer pre,cur and nex to reverse each group. Why? If we observe output, we can see that we have to reverse each group, apart from modifying links of group.
    -> Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
    -> For each iteration, point cur to pre->next and nex to nex->next.
    -> Start nested iteration for length of k.
    -> For each iteration, modify links as following steps:-

        cur->next = nex->next
        nex->next = pre->next
        pre->next = nex
        nex = cur->next

    -> Move pre to cur and reduce length by k.

Time Complexity: O(N)
Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    if(head == NULL|| head->next == NULL) return head;

    int length = lengthOfLinkedList(head);

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;

    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i = 1;i < k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}