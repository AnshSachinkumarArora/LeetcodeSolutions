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
  bool isPalindrome(ListNode *head) {
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
    
    //compare elements of the 2 lists
    while(p1 != nullptr && p2 != nullptr) {
      if(p1->val != p2->val) {
        return false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return true;
  }
};
