/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head; //empty list or single item list is sorted and has no repetition
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        
        while(ptr2 != NULL){
            if(ptr1->val == ptr2->val){
                ptr1->next = ptr2->next;
                ptr2 = ptr2->next;
            }
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        return head;
    }
};