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
        Node *curr=head,*next;
        //make copy of each node, n link them side by side with original nodes- optimised SC O(1)
        while(curr)
        {
            next=curr->next;
            Node* copy=new Node(curr->val);
            curr->next=copy;
            copy->next=next;
            
            curr=next;
        }
        
        //connecting random nodes for copied nodes
        curr=head;
        while(curr)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        
        //restore deep copy separately
        curr=head;
        Node* dummy=new Node(0);
        Node* copy, *copyTail=dummy;
        
        while(curr)
        {
            next=curr->next->next;
            
            //extract the copy
            copy=curr->next;
            copyTail->next=copy;
            copyTail=copy;
            
            //restore original list
            curr->next=next;
            curr=next;
        }
        
        
        return dummy->next;
    }
};