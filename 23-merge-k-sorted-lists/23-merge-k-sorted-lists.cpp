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
class cmp{
  public:
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        while(!pq.empty())
        {
            ListNode* t=pq.top();
            tail->next=t;
            tail=t;
            pq.pop();
            if(t->next!=NULL)
                pq.push(t->next);
        }
        
        return dummy->next;
    }
};