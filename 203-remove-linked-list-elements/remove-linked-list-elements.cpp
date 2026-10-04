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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);  // new list dummy naam ki 
        ListNode* prev = dummy;  // 2 pointer for storing prev and current nodes
        ListNode* curr = head;
        while (curr) {
            if (curr->val == val)           // agar avl milti h to curr ko skip krdo
                prev->next = curr->next;
            else {
                prev = curr;    // nahi mili to eak eak badate rho  
            }
            curr = curr->next;
        }
        return dummy -> next;       // dummy k next head h islye ye return krdo
    }
};