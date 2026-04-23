// Problem: Reverse a doubly ll
// Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// TC: O(N) SC: O(1)

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head == NULL || head->next == NULL)
        return head;
        
        Node* curr = head;
        while(curr!=NULL)
        {
            Node*temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            
            head = curr;
            curr = temp;
        }
        return head;
    }
};
