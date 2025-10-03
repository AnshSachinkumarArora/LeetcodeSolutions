using namespace std;

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  vector<int> findNumbers(vector<int> &nums) {
    // TODO: Write your code here
    int i = 0;
    while (i < nums.size()) {
      // If the current number is not in its correct position, swap it
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        i++;
      }
    }

    // Iterate through the vector to find the first misplaced number
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != j + 1) {
        return vector<int>{nums[j], j + 1};
      }
    }
    return vector<int>{-1, -1};
  }
};

