/* IDEA: 
NOTE:  If both the list has the same length of nodes, then this problem is very simple. 
        Since it has got different lengths, we need to follow different approach.
        
APPROACH: --> Traverse the shorter one and the longer one at the same time, by using pointers. 
          --> Once we reach the end of shorter one, then we will set that pointer to the head of the longer one. 
          --> Similarly once we reach the end of longer one, then we will set that pointer to the head of the shorter one.  
          --> So, in the second iteration, the difference in length would get cancelled, and then they will find the intersecting node.
          
**********************************************************************************************************************************************/
       
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        
        if(tempA == NULL || tempB == NULL) 
       {
           return NULL;
       }
        
        //untill the tempA is not equal to tempB 
        while(tempA != tempB)
        {
            tempA = tempA->next; //traverse the list A
            tempB = tempB->next; //traverse the list B
 
            if(tempA == NULL){    
                tempA = headB; }
            
            if(tempB == NULL){    
                tempB = headA; }
            
            if(tempA == tempB){ 
                return tempA; }
        }
        
        return tempA; 
    }  
};
