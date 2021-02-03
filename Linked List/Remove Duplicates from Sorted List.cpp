class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = head;
        ListNode* temp = head->next;
        
        while(temp!=NULL)
        {
            if(temp->val == prev->val)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
};
