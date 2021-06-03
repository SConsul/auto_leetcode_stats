/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;    
        // Duplication
        Node* curr = head;
        Node* next = head;
        while(curr){
            next = curr->next;
            Node* copy = new Node(curr->val);
            // cout << "Copy ID: " << copy << endl;
            curr->next = copy;
            copy->next = next;
            curr = next;
        }
        // Getting random
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Removing extra connections
        Node*head_copy = head->next;
        curr = head;
        next = head;
        while(curr->next->next){
            next = curr->next->next;
            curr->next->next = next->next;
            curr->next = next;
            curr = next;
        }
        curr->next = NULL;
        return head_copy;
    }
    
};

