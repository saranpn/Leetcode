#include <iostream>

using namespace std;

class ListNode
{
  public:
    int val;
    ListNode* next;

    ListNode(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

int main()
{
    ListNode* head =  new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    return 0;
}
