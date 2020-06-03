/* Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function */ 

/*  IDEA: Since we don't have head pointer, we follow this method. 
          Instead of deleting the given node, delete the next node. 
          But, make a copy of that next node, and delete that node. 
*/

class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode *temp; //create a node called temp in stack
        temp = node->next; //make temp to point on given node's next
        node->val = temp->val; //copy the value of the temp's node and store it in the node's node.
        node->next = temp->next; //make node's next to point on temp's next
        delete temp; //delete that temp node
    }
};
