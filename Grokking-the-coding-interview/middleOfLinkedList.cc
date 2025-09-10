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
  ListNode *findMiddle(ListNode *head) {
    // TODO: Write your code here
    ListNode *slow = head;
    ListNode *fast = head;
    int index = 1;
    while(fast != nullptr && fast->next != nullptr) {
      index = fast->val;
      fast = fast->next->next;
      slow = slow->next;
      if(fast == nullptr) {
        index++;
      } else {
        index+=2;
      }
    }
    while(slow->val != (index/2)+1) {
      slow = slow->next;
    }
    return slow;
  }
};
