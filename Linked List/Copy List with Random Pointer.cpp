class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)return NULL;
        
        map<Node*,Node*>MyMap; //Create a Map 
        Node *node = head->next;
        
        Node *nhead = new Node(head->val); //Create First Clone Node and initialize with head's val 
        Node *tnode = nhead; //Crate a pointer for newly created Clone's Node 
        
        MyMap[head] = nhead; //
        
        while(node != NULL)
        {
            tnode->next = new Node(node->val);
            MyMap[node] = tnode->next;
            tnode = tnode->next;
            node = node ->next;
        }
        
        node = head;
        tnode = nhead;
        
        while(node != NULL)
        {
            if(node->random != NULL)
                tnode->random = MyMap[node->random];
            
            node = node->next;
            tnode = tnode->next;
        }
        
        return nhead;
    }
};

/* 
1.Create a Map of Node type 
2.Create a 1st Clone Node and initialize it to head->val 
3.Create a pointer for Clone Node (ptr) and Original Node (Temp) 
4.While loop (ptr != NULL)
{
Create a New Node and store the Original Linked List Value
Store the pair(Original and New Linked List) in the Map 
Increment Temp pointer 
Increment ptr pointer 
}

5.Make both the pointer to point at their respective head Nodes 
6.While(ptr != NULL)
{
If(ptr->random != NULL)
Temp->random = Map(ptr->random)

Increment ptr
Increment Temp 
}

7.Finally return NewHead
*/
