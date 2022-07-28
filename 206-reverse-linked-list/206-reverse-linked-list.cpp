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
        if(head==NULL)
            return head;
        ListNode* dummy=NULL;
        if(head->next==NULL)
            return head;
        ListNode* nxt=head->next;
        while(nxt)
        {
            head->next=dummy;
            dummy=head;
            head=nxt;
            nxt=nxt->next;
        }
        head->next=dummy;
        dummy=head;
        return dummy;
        
    }
};