/*
CS-> https://www.codingninjas.com/codestudio/problems/799352?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
LC-> 234
-----------------------------------------------------
Input: head = [1,2,3,3,2,1] 
Output: true
______________
Solution 2: Optimized Solution

Approach:

    Following are the steps to this approach:-

        -> Find the middle element of the linked list. Refer to this article to know the steps 
        -> Reverse linked list from next element of middle element. Refer to this article to know the steps 
        -> Iterate through the new list until the middle element reaches the end of the list.
        -> Use a dummy node to check if the same element exists in the linked list from the middle element.

Time Complexity: O(N/2)+O(N/2)+O(N/2)

Reason: O(N/2) for finding the middle element, reversing the list from the middle element, and traversing again to find palindrome respectively.

Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int>* reverseIterative(LinkedListNode<int> *head){

    LinkedListNode<int>* prevptr = NULL;
    LinkedListNode<int>* currptr = head;
    LinkedListNode<int>* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL){
        return true;
    }

    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverseIterative(slow->next);
    slow = slow->next;
    
    while(slow != NULL){
        if(head->data != slow->data){
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}