class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL)
        {
            return true;
        }
        
        vector<int> result; 
        
        while(head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }
        
        int len = result.size();
        
        for(int i=0; i<len/2; i++)
        {
            if(result[i] != result[len-i-1])
            {
                return false;
            }
        }    
            return true;
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
