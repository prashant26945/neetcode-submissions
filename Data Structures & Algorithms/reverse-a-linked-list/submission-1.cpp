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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *NEXT = head;
        while(curr){
            NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
    return prev;
    //  (RECURSIVE METHOD)
        //    if(head == NULL || head->next == NULL) return head;
        //    ListNode* new_Head = reverseList(head->next);
        //    head->next->next = head;
        //    head->next = NULL;
        //    return new_Head;
    }
};
