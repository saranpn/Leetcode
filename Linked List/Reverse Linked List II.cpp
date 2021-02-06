class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head == NULL) return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        
        for(int i=0; curr !=NULL && i<m-1; i++)
        {
            prev = curr; //Pointing to Previous node of Sub-list 
            curr = curr->next; //Pointing to the Sub-list Node 
        }
        
        ListNode* lastNodeOfFirstPart = prev; 
        ListNode* lastNodeOfSubList = curr;
        
       ListNode* after = NULL;
        
        for(int i=0; curr != NULL && i< n-m+1; i++)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;  
        }
        
        //Connect the last Node of first part to the first Node of Sub-List
        if(lastNodeOfFirstPart != NULL) lastNodeOfFirstPart->next = prev;
        else head = prev;
    
        //Connect the last Node of sub-list to the remaining node in the list 
        lastNodeOfSubList->next = curr; 
        
        return head;
    }
};
