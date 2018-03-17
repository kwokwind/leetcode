/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
*/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return nullptr;
        
        if (m == n)
            return head;
        
        // find start pointer and end pointer
        ListNode* start = head;
        ListNode* pre_start = nullptr;
        ListNode* end = head;
        ListNode* after_end = nullptr;
        
        int i = 1;
        int j = 1;
        while (i < m || j < n) {
            if (i < m && start != nullptr) {
                pre_start = start;
                start = start->next;
            }
            
            if (j < n && end->next != nullptr) {
                end = end->next;
                after_end = end->next;
            }
            
            ++i;
            ++j;
        }

        // reverse from start to end
        ListNode* p1 = start;
        ListNode* p2 = start->next;
        while(p1 != end) {
            ListNode* tmp = p2->next;
            p2->next = p1;
            
            p1 = p2;
            p2 = tmp;
        }
        
        // sort new link
        if (pre_start != nullptr)
            pre_start->next = p1;
        else
            head = p1;

        start->next = after_end;

        return head;
    }
};
