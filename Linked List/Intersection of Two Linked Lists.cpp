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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* tempA = headA; //pointer for list A
        ListNode* tempB = headB; //Pointer for list B
        
        //if listA or listB is equal to Null, then no intersection. So return Null
        if(tempA == NULL || tempB == NULL) return NULL;
        
        while(tempA != tempB) //when there is no intersection,
        {
            tempA = tempA->next; //Traverse list A
            tempB = tempB->next; //Traverse list B
            
            if(tempA == tempB) return tempA; //if we found the intersection return 
            
            else if(tempA == NULL) tempA = headB; //if we reach end of list A, then make list A pointer to point on head of list B
            
            else if(tempB == NULL) tempB = headA; //if we reach end of list B, then make list B pointer to point on head of list A
        }
        
        return tempA; //Finally return either tempA or tempB
    }
};
