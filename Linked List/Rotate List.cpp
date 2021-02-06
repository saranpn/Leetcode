//***************************************************************** SOLUTION 1: Using First and Second Pointers *************************************************************
//Time: O(N)
//Space: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL) return head;
        
        //Edge Case 1: If k=0 
        if(k == 0) return head; 
        
        ListNode* first = head;
        ListNode* second = head;
        
        int n = 0;
        
        while(first!=NULL)
        {
            n++;
            first = first->next;
        }
        
        //Edge Case 2: If k is a large number 
        k = k%n;
        first = head;
        
        for(int i=0; i<k; i++)
        {
            first = first->next; 
        }
        
        while(first->next!=NULL)
        {
            first = first->next; 
            second = second->next; 
        }
        
        first->next = head;
        head = second->next;
        second->next = NULL;
        
        return head;
    }
};
