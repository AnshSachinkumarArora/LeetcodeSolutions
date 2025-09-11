using namespace std;
#include <iostream>

/*class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};*/

class Solution {
public:
  ListNode *findCycleStart(ListNode *head) {
    // TODO: Write your code here
    ListNode *slow = head;
    ListNode *fast = head;
    while(true) {
      slow = slow->next;
      fast = fast->next->next;
      if(fast == slow) {
        break;
      }
    }
    slow = head;
    while(fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
