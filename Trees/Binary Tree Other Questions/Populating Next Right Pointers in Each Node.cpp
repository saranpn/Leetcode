/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {   
        //Base case: If root is NULL, then return NULL 
        if(root == NULL) return NULL;
        
        //Create a Queue 
        queue<Node*> Q; 
		
	    //Push the root into the Queue
        Q.push(root);
        //Whenever we finish a level in the tree we also push NULL to the Queue 
        //Since root is the only element in the first level, we push both root and NULL to the Queue 
        Q.push(NULL);
        
        //Traverse until the Queue is not empty 
        while(!Q.empty())
        {
            Node* curr = Q.front(); //Create a pointer and make it to point on front element of the Queue
            Q.pop(); //Pop out the front element from the Queue
			
            //if current Node is NOT NULL and Queue is NOT EMPTY, then point the next pointer to the Queue's front Node
            if(curr != NULL && !Q.empty()) curr->next = Q.front();
            
            //if current Node is NOT NULL and curr->left is not NULL, then push left node into the Queue
            if(curr != NULL && curr->left != NULL) Q.push(curr->left);
            
            //if current Node is NOT NULL and curr->righ is not NULL, then push right node into the Queue
            if(curr != NULL && curr->right != NULL) Q.push(curr->right);
            
            //if current Node is NULL and Queue is NOT EMPTY, then we have reached the end node of some level in the tree. At that time we need to push NULL to the Queue 
	    //Because as per the question, at the end of one level, the last node should point to NULL 
            if(curr == NULL && !Q.empty()) Q.push(NULL);
        }  
        return root;
    }
};

