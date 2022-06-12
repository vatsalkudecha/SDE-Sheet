/*
CS-> https://www.codingninjas.com/codestudio/problems/873376?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC-> 138

YT soln video: https://www.youtube.com/watch?v=VNf6VynfpdM
____________________
Image

Q) Given a linked list having two pointers in each node. The first one points to the next node of the list, however, the other pointer is random and can point to any node of the list or null. The task is to create a deep copy of the given linked list and return its head. We will validate whether the linked list is a copy of the original linked list or not.
A deep copy of a Linked List means we do not copy the references of the nodes of the original Linked List rather for each node in the original Linked List, a new node is created.


*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head == NULL) return head;
    
    // extra space to store the copy

    
    unordered_map<Node*, Node*> mp;
    Node* temp = head;
    while(temp){
        Node* cur = new Node(temp->val);
        mp[temp] = cur;
        temp = temp->next;
    }
    
    temp = head;
    while(temp){
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    
    return mp[head];
}