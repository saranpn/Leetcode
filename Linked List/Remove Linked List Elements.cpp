//********************************** SOLUTION 1:  Using Two Pointer **************************************************************
// Time: O(N)
//Space: O(1) 

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //What if, the first node has the val, then move the head to head's next 
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }
        
        ListNode *temp = head; //pointer 1
        ListNode *prev = head; //pointer 2
        
        while(temp != NULL)
        {
            if(temp->val == val)
            {
                prev->next = temp->next; 
                temp = temp->next; //and continue traversal for temp pointer 
            }
            else
            {
                prev = temp;       //continue traversal for both prev and temp pointer 
                temp = temp->next; 
            }
        }
     return head;    
    }
};

//********************************** SOLUTION 2: Using One Pointer **************************************************************
// Time: O(N)
//Space: O(1) 

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //What if, the first node has the val, then move the head to head's next 
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }
        
        ListNode *temp = head; //Create a pointer 
        
        while(temp != NULL && temp->next != NULL) 
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next; //Make temp next to point on temp's next next 
            }
            else
            {
                temp = temp->next; //normal traversal 
            }
        }
        return head; 
    }
    
    //********************************** SOLUTION 3: Using Vector (Won't work for all the cases) ****************************
    class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while(head!=NULL && head->val == val)
        {
            head = head->next; 
        }
        
        vector<int> result; 
        
        ListNode* temp = head;
        
        //push into the result by removing that element 
        while(temp!=NULL)
        {
            if(temp->val != val)
            {
                result.push_back(temp->val);
            }
            
            temp = temp->next;
        }
        
        temp = head; 
        int n = result.size();
        
        for(int i=0; i<n; i++)
        {
            temp->val = result[i];
            if(i <n-1)
            {
                temp= temp->next;
            } 
        }
        temp->next = NULL;
        return head; 
    }
};
    
};
