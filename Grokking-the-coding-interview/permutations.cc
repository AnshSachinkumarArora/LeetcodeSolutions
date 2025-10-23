using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    // TODO: Write your code here
    queue<vector<int>> q;
    q.push(vector<int> ());
    for(auto num : nums) {
      int size = q.size();
      for(int i = 0; i < size; i++) {
        vector<int> curr = q.front();
        q.pop();
        for(int j = 0; j <= curr.size(); j++) {
          vector<int> temp(curr);
          temp.insert(temp.begin() + j, num);
          if(temp.size() == nums.size()) result.push_back(temp);
          else q.push(temp);
        }
      }
    }
    return result;
  }
};

