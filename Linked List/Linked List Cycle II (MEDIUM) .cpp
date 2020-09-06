/* NOTE: The distance where the slow and start pointer meets to the start of the cycle 
                                     AND 
         The distance from head pointer to the start of the cycle 
         
         = Will be the Same. 
*******************************************************************************************************************/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL) return NULL; 
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next; 
            
            if(slow == fast)
            {
                while(slow != head)
                {
                  slow = slow->next;
                  head = head->next;
                }
                return slow; 
            }
        }
        return NULL;    
    }
};
