using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    // TODO: Write your code here
    int start = 0;
    int currMult = 1;
    for(int end = 0; end < arr.size(); end++) {
      if(arr[end] < target) {
        vector<int> temp = {arr[end]};
        result.push_back(temp);
      }
      currMult *= arr[end];
      while(start <= end && currMult >= target) {
        currMult /= arr[start++];
      }
      int looper = start;
      while(looper < end) {
        vector<int> temp(arr.begin()+looper, arr.begin()+end+1);
        result.push_back(temp);
        looper++;
      }
    }
    return result;
  }
};

