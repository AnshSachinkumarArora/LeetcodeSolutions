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
  ListNode* reorder(ListNode *head) {
    // TODO: Write your code here
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    
    //reverse linked list from midpoint
    ListNode *p1 = nullptr;
    ListNode *p2 = slow;
    while(p2 != nullptr && p2->next != nullptr) {
      ListNode *p3 = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
      p3 = p3->next;
    }
    p2->next = p1;
    p1 = head;
    
    while(p1 != p2 && p1->next != p2) {
      ListNode *tempH = p1->next;
      ListNode *tempT = p2->next;
      p1->next = p2;
      p2->next = tempH;
      p1 = tempH;
      p2 = tempT;
    }
    return head;
  }
};
