
//************************************* Solution 1: Using Counter ********************************************************
//Time: ON) (Where we are traversing the list almost twice) 
//Space: O(1) (Constant space) 

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
        
        //Everytime we have to check fast pointer AND fast->next pointer is NOT NULL, if any one of this is NULL, then it won't enter the while loop 
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next; //move by 1 place
            fast = fast->next->next; //move by 2 place
        }
        
        return slow;
    }
};



//************************************* Solution 2: Using Counter ********************************************************
//Time: ON) (Where we are traversing the list almost twice) 
//Space: O(1) (Constant space) 

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        int count = 0;  //initialize counter 
        
        ListNode* temp = head; //create a pointer 
        
        while(temp!=NULL) 
        {
            count++; //make a count of number of nodes 
            temp = temp->next; 
        }
        
        temp = head; //Again make the temp pointer to point on head 
        
        for(int i=0; i<count/2; i++) //Then travel upto the 
        {
            temp = temp->next;
        }
        
        return temp; //Finally return the temp node 
        
    }
};
