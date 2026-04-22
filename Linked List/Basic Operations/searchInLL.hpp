//Problem: Search in a Linked List
// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

//TC: O(N) SC: O(1)
 /*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* node=head;
        while(node != NULL)
        {
            if(node->data == key)
            return true;
            
            node=node->next;
        }
        return false;
    }
};


//Recursive Approach
// TC: 𝑂(𝑛) — same traversal of all nodes.
// SC: 𝑂(𝑛) — because each recursive call adds a frame to the call stack.In the worst case (key not found, or at the last node), you’ll have 𝑛 recursive calls stacked.

bool searchKey(Node* head, int key) {
    if(head == NULL) return false;
    if(head->data == key) return true;
    return searchKey(head->next, key);
}

