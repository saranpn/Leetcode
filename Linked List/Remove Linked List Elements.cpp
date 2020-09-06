class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //What if, the first node has the val, then move the head to head's next 
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }
        
        ListNode *temp = head; //Create a pointer 
        
        while(temp != NULL && temp->next != NULL) 
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next; //Make temp next to point on temp's next next 
            }
            else
            {
                temp = temp->next; //normal traversal 
            }
        }
        
        return head; 
    }
};
