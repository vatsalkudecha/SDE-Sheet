/*
CS-> https://www.codingninjas.com/codestudio/problems/799897?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Lc -> 206

Input Format: 
head = [3,6,8,10]
This means the given linked list is 3->6->8->10 with head pointer at node 3.

Result:
Output = [10,6,8,3]
This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.
--------------------------------------------------------------
Reverse Linked List : Iterative
TC-> O(N)
SC-> 1
->  We will use three-pointers to traverse through the entire list and interchange links between nodes. One pointer to keep track of the current node in the list. The second one is to keep track of the previous node to the current node and change links. Lastly, a pointer to keep track of nodes in front of current nodes.

Code:
    LinkedListNode<int> *cur = head, *prev = NULL, *nxt;
    while(cur)
    {
        nxt = cur->next;
        cur->next = prev;
        
        prev = cur;
        cur = nxt;
    }
____________________________________________________________
Reverse a Linked List : Recursive
TC-> O(N)
SC-> 1

-> We traverse to the end of the list recursively.

-> As we reach the end of the list, we make the end node the head. Then receive previous nodes and make them connected to the last one.

-> At last, we link the second node to the head and the first node to NULL. We return to our new head.
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

ListNode* reverseList(ListNode* &head) {

    if (head == NULL || head->next == NULL)
        return head;

    ListNode* nnode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}