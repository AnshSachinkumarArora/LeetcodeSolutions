using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMaxSumSubArray(int k, const vector<int>& arr) {
      int maxSum = 0;
      // TODO: Write your code here
      int windowSum = 0;
      int windowStart = 0;
      for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
        windowSum += arr[windowEnd];

        if(windowEnd >= k-1) {
          maxSum = max(windowSum, maxSum);
          windowSum -= arr[windowStart];
          windowStart++;
        }
      }
      return maxSum;
    }
  };        
