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
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL, *next = NULL, *current = head;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next; 
        }
        return prev;
    }
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode*curr=head, *prev=NULL;
//         int c=1;
//         while(c!=left)
//         {
//             prev=curr;
//             curr=curr->next;
//             c++;
//         }
        
//         ListNode* start=curr;
//         while(c!=right)
//         {
//             curr=curr->next;
//             c++;
//         }
        
//         ListNode* rest = curr->next;
//         curr->next = NULL;
        
//         ListNode* newHead = reverse(start);
//         if (prev!=NULL){
//             prev->next = newHead;

//         }
//         curr = newHead;
//         while(curr->next!=NULL){
//             curr= curr->next;
//         }
//         curr->next = rest;
//         if(left == 1){
//             return newHead;
//         }
//         else{
//             return head;
//         }
        
        ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || left == right){
            return head;
        }
        ListNode* prev, *tail = NULL, *temp = NULL;
        ListNode dummy(NULL);
        prev = &dummy;
        dummy.next = head;
        for(int i=0; i < left-1; i++){
            prev = prev->next;
        }
        tail = prev->next;
        for(int i=0; i< right - left;i++){
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp; 
        }
        
        return dummy.next;
    }
};