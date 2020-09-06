//Link: https://www.youtube.com/watch?v=5cbPl9D-9SE&ab_channel=AmellPeralta

//TWO POINTER Approach: Slow and fast pointer. If both becomes equal at one point, then there is a loop. 

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL) return false; 
        
        ListNode *slow = head; //slow pointer
        ListNode *fast = head; //fast pointer 
        
        //fast != NULL       ==> Will handle the Even case 
        //fast->next != NULL ==> Will handle the Odd case 
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next; //moves one node at a time 
            fast = fast->next->next; //moves two node at a time 
            
            if(slow == fast) //if slow pointer becomes equal to the fast pointer then, there must be a loop
            {
                return true;
            }
        }
        
        return false; //return false, if there is no loop 
    }
};
