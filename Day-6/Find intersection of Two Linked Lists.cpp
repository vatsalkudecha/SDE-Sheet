/*
CS-> https://www.codingninjas.com/codestudio/problems/630457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 160
--------------
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:2
Explanation: Here, both lists intersecting nodes start from node 2.
---------------------------------------------
Sol-1: Brute: Compare each node with every other node of other list
    similar to using 2 for loops
Time Complexity: O(m*n)
Reason: For each node in list 2 entire lists 1 are iterated. 
_______________________________________________________________
Solution 2: Hashing

Approach:
    In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-

    -> Iterate through list 1 and hash its node address. Why? (Hint: depends on common attribute we are searching)
    -> Iterate through list 2 and search the hashed value in the hash table. If found, return node.

Time Complexity: O(n+m)
Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 

Space Complexity: O(n)
Reason: Storing list 1 node addresses in unordered_set.
_____________________________________________________________________
Solution 3: Difference of length

Approach:
        Step1: Find the size of A and B
        Step2: Move till larger linkedlist -> difference number of times
        Step3: start finding common elements from there
        Step4: return either of the nodes, as they are pointing to the intersection.

Time Complexity: O(2*max(len1, len2)) + O(len1 - len2) + O(min(len1, len2))

Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.
_______________________________________________________________________
Solution 4: Optimised 

Approach:

    -> The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-

    -> Take two dummy nodes for each list. Point each to the head of the lists.
    -> Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.        

Time Complexity: O(2*max(length of list1,length of list2))
Reason: Uses the same concept of difference of lengths of two lists.

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

int len(ListNode* head) {
    int count = 0;
    if(head == NULL) {
        return count;
    }
    while(head) {
        head = head->next;
        count++;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // AMAZON
    // optimal-0: Using Hashmap to store the visited Nodes (SC-> n)
    
    // optimal-1 code
    /*
    int size1 = len(headA);
    int size2 = len(headB);
    
    while(size1 > size2) {
        headA = headA->next;
        size1--;
    }
    while(size2 > size1) {
        headB = headB->next;
        size2--;
    }
    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
    */
    
    // Solution 4: Optimised 

    
    ListNode* d1 = headA;
    ListNode* d2 = headB;

    while(d1 != d2) {
        d1 = d1 == NULL ? headB : d1->next;
        d2 = d2 == NULL ? headA : d2->next;
    }

    return d1;
}