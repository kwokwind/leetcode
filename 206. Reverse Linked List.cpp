// Reverse a singly linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 != nullptr) {
            ListNode* tmp = p2->next;
            p2->next = p1;
            
            p1 = p2;
            p2 = tmp;
        }
        
        head->next = nullptr;
        return p1;
    }
};
