class Solution {
public:
    bool isValid(string s) 
    {
        //it has to be even number of characters to make it true 
        if(s.size() % 2 != 0) return false;
        
        stack<char> MyStack; //create a stack 

        for(int i=0; i<s.size(); i++) //traverse through the string once 
        {
            //whenever you see a open bracket, then push it inside the stack 
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                MyStack.push(s[i]);
            } 
            
            else //when you see a close bracket
            {   
                if(MyStack.empty()) return false; //and when the stack is empty, then its false
                
                //when you see a close bracket, then the top element of the stack must be the open bracket of same type
                //if not, return false 
                else if(s[i] == ')' && MyStack.top() !='(') return false;
                else if(s[i] == '}' && MyStack.top() !='{') return false;
                else if(s[i] == ']' && MyStack.top() !='[') return false;
                
                //Means we found the open bracket on top of stack, hence pop out that from the stack 
                MyStack.pop();  
            }
        }
        
        //Finally after this, if the stack is empty, then return true, else return false. 
       return MyStack.empty();
    }
};
