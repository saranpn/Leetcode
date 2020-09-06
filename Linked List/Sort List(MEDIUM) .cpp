class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        vector<int> array; //create an array
        
        ListNode *temp = head; //This pointer is to traverse 1st time to store it into the array
        ListNode *prev = head; //This pointer is to traverse 2nd time to modify the list 
        
        //Traverse the Linked list and store the "val" into the array 
        while(temp != NULL)
        {
            array.push_back(temp->val); //push the val into the array
            temp = temp->next; //traverse
        }
        
        sort(array.begin(),array.end()); //sort the array 
        
        for(int i=0; i<array.size(); i++) //traverse the array 
        {
            prev->val = array[i]; //modify the linked list value as sorted list 
            prev = prev->next; //traverse 
        }
        
        return head; //finally return the list 
    }
};
