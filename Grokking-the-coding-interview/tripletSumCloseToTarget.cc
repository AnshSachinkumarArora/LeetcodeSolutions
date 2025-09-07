using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    int currLowest = 1e9;
    for(int i = 0; i < arr.size()-2; i++) {
      if(i > 0 && arr[i] == arr[i-1]) {
        continue;
      }
      int start = i+1;
      int end = arr.size()-1;
      while(start < end) {
        int currSum = arr[i]+arr[start]+arr[end];
        if(abs(currSum-targetSum) <= abs(currLowest-targetSum)) {
          if(abs(currSum-targetSum) == abs(currLowest-targetSum)) {
            currLowest = min(currSum, currLowest);
          } else {
            currLowest = currSum;
          }
          if(currSum > targetSum) {
            end--;
          } else if (currSum < targetSum) {
            start++;
          } else {
            break;
          }
        } else if(currSum > targetSum) {
          end--;
        } else if (currSum < targetSum) {
          start++;
        }
      }
    }
    return currLowest;
  }
};
