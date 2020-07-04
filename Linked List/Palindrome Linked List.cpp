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
