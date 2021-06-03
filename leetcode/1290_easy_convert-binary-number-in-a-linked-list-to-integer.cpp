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
    int getDecimalValue(ListNode* head) {
        // cout << pow(head->val,2) << endl;
        int count = 1;
        if(head->next !=NULL){
            head->val = head->val * pow(2,getPlace(head->next,count)) + getDecimalValue(head->next);
            // cout << "After: " <<head->val <<" Count: "<< count << endl;
        }
        return head->val;
        
    }
    int getPlace(ListNode*node, int count){
        if(node->next != NULL)
            count += getPlace(node->next, count);
        return count;
    }
};