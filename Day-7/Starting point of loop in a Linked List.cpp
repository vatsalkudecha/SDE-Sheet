/*
CS-> https://www.codingninjas.com/codestudio/problems/1112628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
LC-> 142
--------------------------
Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
------------------------------------------
Solution 1: Brute Force (Using Hashmap)

Approach:
    We can store nodes in a hash table so that, if a loop exists, the head will encounter the same node again. This node will be present in the table and hence, we can detect the loop.

Time Complexity: O(N)
Reason: Iterating the entire list once.

Space Complexity: O(N)
Reason: We store all nodes in a hash table.
__________________________________________________________________
Solution 2: Slow and Fast Pointer Method

Approach:

    The following steps are required:

    -> Initially take two pointers, fast and slow. Fast pointer takes two steps ahead while slow pointer will take single step ahead for each iteration.
    -> We know that if a cycle exists, fast and slow pointers will collide.
    -> Else, when both slow and fast pointer collides, it detects a cycle exists.
    -> Take another pointer, say entry. Point to the very first of the linked list.
    -> Move the slow and the entry pointer ahead by single steps until they collide. 
    -> Once they collide we get the starting node of the linked list.
    -> If cycle does not exists, fast pointer will move to NULL

Time Complexity: O(N)
Reason: We can take overall iterations club it to O(N)

Space Complexity: O(1)
Intuition:

But why use another pointer, entry?

Let’s say a slow pointer covers the L2 distance from the starting node of the cycle until it collides with a fast pointer. L1 be the distance traveled by the entry pointer to the starting node of the cycle. So, in total, the slow pointer covers the L1+L2 distance. We know that a fast pointer covers some steps more than a slow pointer. Therefore, we can say that a fast pointer will surely cover the L1+L2 distance. Plus, a fast pointer will cover more steps which will accumulate to nC length where cC is the length of the cycle and n is the number of turns. Thus, the fast pointer covers the total length of L1+L2+nC. 

We know that the slow pointer travels twice the fast pointer. So this makes equation to

2(L1+L2) = L1+L2+nC. This makes equation to

L1+L2 = nC. Moving L2 to the right side

L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
        
    // Brute Force -> Using Hashmap -> Store nodes
    
    // Optimal -> Tortoise - Haare Method (Slow / Fast Pointers)
    
    if (head == NULL || head->next == NULL)
    return NULL;

    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;  
    
}