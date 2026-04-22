//Problem: Insert at end of LL
//https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

//TC: O(N) SC: O(1)

/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        if(head == NULL) 
          return newNode;
        
        if(head->next == NULL)
         { 
             head->next = newNode;
             return head;
         }
         
         Node* node=head;
        while(node->next != NULL)
        {
            node=node->next;
        }
        node->next=newNode;
        return head;
    }
};
