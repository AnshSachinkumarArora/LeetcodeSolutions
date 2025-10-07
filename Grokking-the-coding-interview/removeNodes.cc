#include <stack>
#include <iostream>
using namespace std;

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // TODO: Write your code here
        stack<ListNode*> s;
        ListNode* counter = head;
        while(counter != nullptr) {
            while(!s.empty() && s.top()->val < counter->val) {
                s.pop();
            }
            if(!s.empty()) {
                s.top()->next = counter;
            }
            s.push(counter);
            if(s.size() == 1) {
                head = s.top();
            }
            counter = counter->next;
        }
        return head;
    }
};

