#include <iostream>
#include <map>
#include <iostream>
#include <vector>

class Solution {
  public:
    int numGoodPairs(std::vector<int>& nums) {
      int pairCount = 0;
      // TODO: Write your code here
      map<int, int> m;
      for(int i : nums) {
        m[i]++;
        pairCount += m[i]-1;
      }
      return pairCount;
    }
};
