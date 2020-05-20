//Author: Saravana Kumar  
//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

/*********************************************************************************************
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*************************************************************************************************/

METHOD 1: Iterative Method - Time Complexity => O(N) and Space Complexity => O(1)

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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev, *curr, *n;
        
        prev = NULL;
        curr = head;
        
        while(curr != NULL)
        {
            n = curr -> next; 
            curr ->next = prev;
            prev = curr;
            curr = n;
        }
        
        head = prev;
        return prev;
    }
};

//****************************************************************************************

//Method 2: Recursion - Time Complexity => O(N) and Space Complexity => O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *p;
        
        //if there are No nodes and if head->next is equal to NULL
        if(head == NULL || head->next == NULL) // STEP 2: if head->next is equal to NULL, then enter the if condition
        {
            return head; //return the head(which has the last Node's address)
        }
        
        /* reverse the rest list and put  
          the first element at the end */
        
// STEP 1: Call recursively until the head->next is NULL
// head keeps moving on till last node
        p = reverseList(head->next); 
        
    //STEP3: We want to make the head Node to point on previous Node's Next
        
//We can access the previous node's next by head->next->next (previous node) = head
        head->next->next = head;  
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return p; 
    }
    
    
};
