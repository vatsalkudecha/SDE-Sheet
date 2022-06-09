/*
CS-> https://www.codingninjas.com/codestudio/problems/973250?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 876

Input Format: 
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]
Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.
----------------------------------------------------------------------------------

Solution 1: Naive Approach (find length, then traverse length/2 nodes)
Time Complexity: O(N) + O(N)
Space Complexity: O(1)

Intuition: We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n , and then traversing for 2nd time for n/2 nodes to get to the middle of the list.
_____________________________________________________________________________
Solution 2: [Efficient] Tortoise-Hare-Approach (Slow/Fast Pointer)
Time Complexity: O(N)
Space Complexity: O(1)

Unlike the above approach, we don’t have to maintain nodes count here and we will be able to find the middle node in a single traversal so this approach is more efficient.

Intuition: 
    In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double than that of the slow pointer. So when the fast ptr will be at the end of Linked List, slow ptr would have covered half of Linked List till then. So slow ptr will be pointing towards the middle of Linked List.

Approach: 

    Create two pointers slow and fast and initialize them to a head pointer.
    Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
    When the above condition is met, we can see that the slow ptr is pointing towards the middle of Linked List and hence we can return the slow pointer.
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

ListNode *findMiddle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}