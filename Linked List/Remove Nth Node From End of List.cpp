/********************************* SOLUTION 1: Using First and Second Pointers *********************************************************
//Time: O(N)
//Space: O(1) 

    --> Create two pointers. Point both of them to head node. 
   --> First move one pointer upto n nodes given. 
   --> Then from that node we can see that second pointer is n nodes behind the first pointer. 
   
   --> Then continue to increment both 1st and 2nd pointer till the 1st pointer reaches null.
   At that time, we will have 2nd pointer n nodes behind 1st pointer, and the 2nd pointer will be 
   pointing to the node that we want to delete.
   
   --> Also keep track of previous node of second pointer by using "prev" pointer    */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// ***********************************************SOLUTION 1: Using First and Second Pointer (One Pass) *****************************************************
//Time: O(N)
//Space: O(1) 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //Base Case
        if(head == NULL) return {}; 
        
        ListNode* first = head; //Create first pointer 
        ListNode* second = head; //Create second pointer
        ListNode* prev = NULL; //Ceate prev pointer to keep track of the previous node to the second pointer 
        
        //First move the temp pointer till n Node
        for(int i=0; i<n; i++)
        {
            first = first->next; 
            
            if(first == NULL) //if the first pointer reaches NULL, that means, the node to be deleted is the head node
            {
                head = head->next;
                return head; 
            }
        }
        
        while(first != NULL) //traverse till first pointer reaches null 
        {
            first = first->next;
            prev = second;
            second = second->next; 
        }
        
        //finally second pointer will reach the node that we want to delete
        //so make prev's next to point on second's next 
        prev->next = second->next; 
        
        return head;   
    }
};





// ***********************************************SOLUTION 2: By Counting (Two Pass) *****************************************************
//Time: O(N)
//Space: O(1) 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL) return {}; //Base Case
        
        ListNode* temp = head;
        int count = 0;
        
        while(temp!=NULL) //Traverse through the list 
        {
            count++;                //and make a count of # of nodes
            temp = temp->next; 
        }
        
        temp = head;          //Again make temp pointer to point on head 
        int end = count - n;  //Find the index of the node, which we want to remove 
        
        ListNode* prev = head; //create a prev pointer to keep track of previous node
        
        if(end == 0)//if the node we want to delete is the head node, 
        {
            head = head->next; // then, make head to point on head's next
            return head;  //and simply return the head 
        }
        
        for(int i=0; i<end; i++) //Traverse till that index node 
        {
            prev = temp; //increment prev pointer
            temp = temp->next; //increment temp pointer 
    
            if(i == end-1) //after we reach that node
                prev->next = temp->next; //Make previous pointer's next to point on temp's next 
        }
        return head; //Finally return head 
    }
};
