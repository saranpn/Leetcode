class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        if(head == NULL)
        {
            return head;
        }
        
        ListNode *fast, *slow;
        
        fast = head;
        slow = head; 
        
//For ODD values given, while looping fast->next will be null at 1 point
//For EVEN values given, while looping fast will be null at 1 point 
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next; //move by 1 place
            fast = fast->next->next; //move by 2 place
        }
        
        return slow;
        
    }
};
