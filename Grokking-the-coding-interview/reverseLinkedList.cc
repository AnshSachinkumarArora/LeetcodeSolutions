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
  ListNode *reverse(ListNode *head) {
    ListNode *result = head;
    // TODO: Write your code here
    ListNode *p1 = nullptr;
    ListNode *p2 = nullptr;
    while(head != nullptr) {
      p1 = head->next;
      head->next = p2;
      p2 = head;
      head = p1;
    }
    return p2;
  }
};

