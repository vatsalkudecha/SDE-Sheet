/*
cs-> https://www.codingninjas.com/codestudio/problems/800332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
lc-> 21

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}
Output :
{1,2,3,5,7,8,10,10}
________________________________________________
Solution 1: Using an externally linked list to store answers.
Time Complexity: O(N+M).

    Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).

Space Complexity: O(N+M).

    We are creating another linked list that contains the (N+M) number of nodes in the list. So, space complexity is O(N+M).
_______________________________________________________________
Solution 2: Inplace method without using extra space.

    The idea to do it without extra space is to play around with the next pointers of nodes in the two input lists and arrange them in a fashion such that all nodes are linked in increasing order of values.

Time Complexity :
    We are still traversing both lists entirely in the worst-case scenario. So, it remains the same as O(N+M) where N is the number of nodes in list 1 and M is the number of nodes in list 2.

Space Complexity :
    We are using the same lists just changing links to create our desired list. So no extra space is used. Hence, its space complexity is O(1). 
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* dummynode = new ListNode(-1);
    ListNode* p3 = dummynode;

    while(p1!= NULL && p2!= NULL){

        if(p1->val < p2->val){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummynode->next;
}