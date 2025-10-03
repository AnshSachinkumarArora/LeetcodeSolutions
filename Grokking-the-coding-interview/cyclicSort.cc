using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<int> sort(vector<int> &nums) {
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      if(nums[i] != i+1) {
        int temp = nums[nums[i]-1];
        nums[nums[i]-1] = nums[i];
        nums[i] = temp;
      } else {
        i++;
      }
    }
    return nums;
  }
};

