//*********************************************************** Solution 1: Using Pointers ***********************************************
//Time: O(N)
//Space: O(1)

/* Idea:  We have one list at the beginning. Then what we do is, we separate all the Odd number nodes and all the Even number nodes. 
          Then we just take the Odd list and connect it to the Even list by using the EvenHead pointer. */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL) return NULL; 
        
        ListNode* Odd = head; //Take a pointer for Odd Nodes
        ListNode* Even = head->next; //Take a pointer for Even Nodes
        ListNode* EvenHead = Even; //And take a pointer for starting position of Even Node 
        
        while(Even != NULL && Even->next != NULL)
        {
            Odd->next = Even->next; //Connect Odd Nodes
            Odd = Odd->next; //Increment Odd pointer 
            Even->next = Odd->next; //Connect Even Nodes
            Even = Even->next; //Increment Even pointer 
        }
        
        Odd->next = EvenHead; //Connect the Tail of the Odd Node to the Head of the Even Node 
        
        return head; //Finall return head 
    }
};
