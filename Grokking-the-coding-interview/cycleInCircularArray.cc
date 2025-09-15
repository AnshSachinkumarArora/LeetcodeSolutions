using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  bool loopExists(const vector<int> &arr) {
    // TODO: Write your code here
    for(int i = 0; i < arr.size(); i++) {
      bool negative = arr[i] < 0;
      int fast = i, slow = i;
      
      do {
        fast = findNext(fast, arr, negative);
        slow = findNext(slow, arr, negative);
        if(fast != -1) {
          fast = findNext(fast, arr, negative);
        }
      } while (slow != -1 && fast != -1 && slow != fast);

      if(slow != -1 && slow == fast) {
        return true;
      }
    }
    return false;
  }

  int findNext(int index, vector<int> arr, bool negative) {
    bool isNegative = arr[index] < 0;
    if(isNegative != negative) {
      return -1;
    }
    int next = index + arr[index];
    next %= arr.size();
    if(next < 0) {
      next += arr.size();
    }

    if(next == index) {
      return -1;
    }
    return next;
  }
};
