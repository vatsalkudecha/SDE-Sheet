/*
CS-> https://www.codingninjas.com/codestudio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
LC-> 430
GFG-> https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

---------------------------------------------------
Input:
Number of head nodes = 4
Array holding length of each list with head and bottom = [4,2,3,4]
Elements of entire linked list = [5,7,8,30,10,20,19,22,50,28,35,40,45]


Output:
    Flattened list = [5,7,8,10,19,20,22,28,30,35,40,45,50]
Explanation:
    Flattened list is the linked list consisting entire elements of the given list in sorted order
______________________________________________________
Approach:

    -> Since each list, followed by the bottom pointer, are in sorted order. Our main aim is to make a single list in sorted order of all nodes. So, we can think of a merge algorithm of merge sort.

    -> The process to flatten the given linked list is as follows:-

        -> We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
        -> Merge each list chosen using the merge algorithm. The steps are
        -> Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and temp pointer is to move ahead as we build the flatten list.
        -> We iterate through the two chosen. Move head from any of the chosen list ahead whose current pointed node is smaller. 
        -> Return the new flattened list found.

Time Complexity: O(N), where N is the total number of nodes present
Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}	
};

Node* merge(Node* a, Node* b) {
    
    Node* res = new Node(0);
    Node* temp = res;
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    temp->next = NULL;
    
    if(a != NULL) {
        temp->bottom = a;
    }
    else {
        temp->bottom = b;
    }
    temp->next = NULL;
    
    return res->bottom;
}
    
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL) {
        return root;
    }
    // calling recursion
    root->next = flatten(root->next);
    
    // merging two linked-list
    root = merge(root, root->next);
    
    return root;
}