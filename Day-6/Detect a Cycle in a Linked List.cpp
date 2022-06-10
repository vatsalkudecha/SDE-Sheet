/*
CS-> https://www.codingninjas.com/codestudio/problems/628974?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC-> 141
------------------------------------------------
Solution: Hashing

Approach:

    We need to keep track of all the nodes we have visited till now so that once we visit the same node again we can say that a cycle is detected

Time Complexity: O(N)
Reason: Entire list is iterated once.

Space Complexity: O(N)
Reason: All nodes present in the list are stored in a hash table.
______________________________________________________________________________

Solution- 2: Slow and Faster Pointer(Image)

Approach:

    -> We will use two pointers with different steps forward. The process is as follows:-

    -> We will take two pointers, namely fast and slow. Fast pointer takes 2 steps ahead and slow pointer takes 2 points ahead.
    -> Iterate through the list until the fast pointer is equal to NULL. This is because NULL indicates that there is no cycle present in the given list.
    -> Cycle can be detected when fast and slow pointers collide.
    
Time Complexity: O(N)
Reason: In the worst case, all the nodes of the list are visited.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    // Brute-> Using Hashmap
    // TC-> O(n), SC-> O(n)
    if(head == NULL || head->next == NULL) {
        return false;
    }
    // Floyd's Algo - Hare and tortoise - Slow and fast pointer
    // TC-> O(n), SC-> O(1)
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}