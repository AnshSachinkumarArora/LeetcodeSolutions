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
  ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    ListNode *start = head;
    ListNode *current = nullptr;
    while(start != nullptr) {
      ListNode *next = nullptr;
      ListNode *lastPrev = current;
      ListNode *lastCurr = start;

      for(int i = 0; start != nullptr && i < k; i++) {
        next = start->next;
        start->next = current;
        current = start;
        start = next;
      }

      if(lastPrev != nullptr) {
        lastPrev->next = current;
      } else {
        head = current;
      }

      lastCurr->next = start;
      current = lastCurr;
    }
    return head;
  }
};

