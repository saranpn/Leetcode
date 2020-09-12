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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev, *curr, *NEXT;
        
        prev = NULL; //initializing pointer 1
        curr = head; //initializing pointer 2
        
        while(curr != NULL)
        {
            NEXT = curr->next; //initializing pointer 3 (inside while loop)
            curr->next = prev; //Reverse the curr->next 
            prev = curr; //increment the previous pointer 
            curr = NEXT; //increment the current pointer 
        }
        
        head = prev; //prev will the last node, so point the head to that node
        return head; //Finally return head
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


//*************************************** SOLUTION 3: Using Stack *****************************************************************
//Time: O(N) (Traversing the list and stack once)
//Space: O(N) (For Stack) 

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        stack<int> MyStack; //Create a Stack 
        
        ListNode *temp = head; // Create a pointer called temp and make it to point to head
        
        while(temp != NULL) //Continue until temp reaches null 
        {
            MyStack.push(temp->val); //Push the value of the node into the stack 
            temp = temp->next; //traverse the list 
        }
        
        temp = head; //Make temp node to point it back to the head (Which was pointing on the NULL before)
        
        while(!MyStack.empty()) //Continue until the stack becomes empty
        {
            temp->val = MyStack.top(); //Make temp->val to be be equal to top value from the stack
            MyStack.pop(); //Pop out the top element from the stack
            temp = temp->next; //Taverse the list 
        }
        
        return head; //Finally return the head 
    }
};
