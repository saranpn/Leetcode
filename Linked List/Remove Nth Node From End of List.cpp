



// ********************************************************** By Traversing List Twice **********************************************************
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL && head->next == NULL) return NULL;
        
        int count = 0; //to count the number of nodes 

        ListNode *temp = head; //pointer to traverse while counting 
        
        //counting is done 
        while(temp != NULL)
        {
            count ++;
            temp = temp->next;
        }
        
        //After Counting, traverse upto that node, and delete it 
        ListNode *curr = head; //To traverse to that node 
        ListNode *prev = NULL; //To make pointer for previous node 
        
        int i = 1;             
        int m = count-n+1;
        
        while(i<=m)
        {
            if(i<m) //if we still didn't reach that node, then continue moving the pointers 
            {
                prev = curr;
                curr = curr->next; 
                i++;
            }
            
            //if we reach that node, and if that is the 1st node in the linked list, then we need to modify the head pointer too. 
            else if(i == m && i == 1)
            {
                prev = curr;
                curr = curr->next;
                head = curr;
                i++;
            }
            
            //if we reach that node 
            else if(i == m)
            {
                prev->next = curr->next;
                i++;
            }  
        }
        return head; 
    }
};
