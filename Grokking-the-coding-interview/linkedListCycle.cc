using namespace std;

#include <iostream>

class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // TODO: Write your code here
    ListNode *fast = head;
    ListNode *slow = head;
    while(true) {
      if(fast->next != nullptr && slow->next != nullptr) {
        cout<<"fast: "<<fast->val<<" slow: "<<slow->val<<endl;
        fast = fast->next->next;
        slow = slow->next;
        if(fast == nullptr) {
          return false;
        } else if (fast->val == slow->val) {
          return true;
        }
      } else {
        return false;
      }
      
    }
    return false;
  }
};
