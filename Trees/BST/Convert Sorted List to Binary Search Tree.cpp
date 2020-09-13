//First into array, then do like previous problem 

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        ListNode* temp = head;
        vector<int> nums;
        
        if(head == NULL) return {};
        
        while(temp!=NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next; 
        }
        
        int n = nums.size(); 
        
        return RecursiveSol(nums,0,n-1);
    }
    
    TreeNode* RecursiveSol(vector<int>&nums,int start, int end)
    {
        if(start > end) return {};
        
        int middle = start + (end-start+1)/2; 
        
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = RecursiveSol(nums, start, middle-1);
        root->right = RecursiveSol(nums, middle+1, end);
        
        return root;
    }
    
};
