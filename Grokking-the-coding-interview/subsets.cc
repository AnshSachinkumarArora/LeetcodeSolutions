using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets = {{}};
    // TODO: Write your code here
    for(int num : nums) {
      int size = subsets.size();
      for(int i = 0; i < size; i++) {
        vector<int> newSet(subsets[i]);
        newSet.push_back(num);
        subsets.push_back(newSet);
      }
    }
    return subsets;
  }
};    

