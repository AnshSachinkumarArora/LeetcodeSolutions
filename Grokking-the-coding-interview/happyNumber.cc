using namespace std;
#include <iostream>
#include <string>

class Solution {
public:
  bool find(int num) {
    // TODO: Write your code here
    int slow = num;
    int fast = num;
    do {
      if (squaredSum(slow) == 1 || squaredSum(fast) == 1) {
        return true;
      }
      slow = squaredSum(slow);
      fast = squaredSum(squaredSum(fast));
    }
    while(slow != fast);
    return false;
  }

public:
  int squaredSum(int num) {
    string s = std::to_string(num);
    int sum = 0;
    for(char c : s) {
      sum += (atoi(&c) * atoi(&c));
    }
    return sum;
  }
};
