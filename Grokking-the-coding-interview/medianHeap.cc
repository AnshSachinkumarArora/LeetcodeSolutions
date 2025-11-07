using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  priority_queue<int> max;
  priority_queue<int, vector<int>, greater<int>> min;

  Solution() {
    // TODO: Write your code here
  }

  void insertNum(int num) {
    // TODO: Write your code here
    if(max.empty() || max.top() >= num) max.push(num);
    else min.push(num);
    rebalance();
  }

  double findMedian() {
    // TODO: Write your code here
    if(min.size() == max.size()) return ((min.top()+max.top())/2.0);
    if(min.size() > max.size()) return min.top();
    else return max.top();
  }

  void rebalance() {
    if(min.size() > max.size()+1) {
      max.push(min.top());
      min.pop();
    } else if (min.size()+1 < max.size()) {
      min.push(max.top());
      max.pop();
    }  
  }

};

