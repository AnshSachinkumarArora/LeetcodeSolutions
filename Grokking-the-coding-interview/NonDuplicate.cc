using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  int moveElements(vector<int> &arr) {
    // TODO: Write your code here
    vector<int> res = {arr[0]};
    for(int i = 1; i < arr.size(); i++) {
      int cur = arr[i];
      int prev = arr[i-1];
      if (cur != prev) {
        res.push_back(cur);
      }
    }
    return res.size();
  }
};
