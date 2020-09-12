//*****************************************************  SOLUTION 1: Using Array ****************************************************
//Time: O(N)
//Space: O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL) return true;
        
        vector<int> result; 
        
        while(head != NULL) //Push into the result array 
        {
            result.push_back(head->val);
            head = head->next;
        }
        
        int len = result.size(); //Get the size of the array 
        
        for(int i=0; i<len/2; i++) //Traverse only half of the array 
        {
            if(result[i] != result[len-i-1]) //compare first and last value of the array 
            {
                return false; //if not same, return false 
            }
        }    
            return true; //if same, return true
    }
};


//*************************************** SOLUTION 2: Using Stack **********************************************************
//Time: O(N)
//Space: O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return true;
        
        stack<int> MyStack; 
        
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            MyStack.push(temp->val);
            temp = temp->next; 
        }
        
        temp = head; 
        
        while(temp!=NULL)
        {
            int n = MyStack.top();
            if(temp->val != n) 
            { return false; }
            temp = temp->next;
            MyStack.pop();
        }
        
        return true; 
    }
};
