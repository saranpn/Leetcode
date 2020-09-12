//Time: O(N*M) 
//Space: O(N+M) 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        //Here there are only 2 LinkedList with no head pointer
        //Therefore we need to create a dummy node for head pointer 
        
        //Dummy Node's val is NOT important, so keep it as -1
        //Dummy Node's Next is Very Important (That is what act as head pointer)
        ListNode* dummy = new ListNode(-1);
        
        //We don't want to move the dummy head pointer, so we create new temp pointer 
        //and make it to point on dummy head 
        ListNode* temp = dummy;
        
        //When we have Nodes on both Linked Lists, then
        while(l1 != NULL && l2 != NULL)
        {
            //Compare which one is smaller 
            if(l1->val < l2->val)
            {
                temp->next = l1; //then make temp->next to pointer to point on that node
                temp = l1; //increment the temp node
                l1 = l1->next; //increment the l1 pointer 
            }
            else //for other cases like l2->val is smaller, and both l1->val and l2->val equal 
            {
                temp->next = l2; //then make temp->next to pointer to point on that node
                temp = l2;  //increment the temp node
                l2 = l2->next; //increment the l2 pointer 
            }
        }
        
        if(l1 == NULL) temp->next = l2; //if l1 node becomes Null, then continue moving wiht l2 node 
            
        if(l2 == NULL) temp->next = l1; //if l2 node becomes Null, then continue moving wiht l1 node
            
        return dummy->next; //Finally return the dummy->next 
        
    }
};
