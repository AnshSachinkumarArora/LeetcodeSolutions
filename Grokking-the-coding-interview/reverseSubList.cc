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
  ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here
    ListNode *counter = head, *p1 = head, *p2 = nullptr;
    for(int i = 0; p1 != nullptr && i < p-1; i++) {
      p2 = p1;
      p1 = p1->next;
    }
    ListNode *last = p1;
    ListNode *beforeLast = p2;

    ListNode *p3 = nullptr;
    for(int i = 0; p1 != nullptr && i < q-p+1; i++) {
      p3 = p1->next;
      p1->next = p2;
      p2 = p1;
      p1 = p3;
    }

    last->next = p1;

    if(beforeLast == nullptr) {
      head = p2;
    } else {
      beforeLast->next = p2;
    }
    return head;
  }
};
    

