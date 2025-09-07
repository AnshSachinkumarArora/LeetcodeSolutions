using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  static int sort(const vector<int>& arr) {
    // TODO: Write your code here
    int low = 0;
    int high = arr.size()-1;
    while(low < arr.size()-1 && arr[low] <= arr[low+1]) {
      low++;
    }
    if (low == arr.size()-1) {
      return 0;
    }
    while(high > 0 && arr[high] >= arr[high-1]) {
      high--;
    }
    int small = numeric_limits<int>::max(), large = numeric_limits<int>::min();
    for (int i = low; i <= high; i++) {
      small = min(small, arr[i]);
      large = max(large, arr[i]);
    }
    while(low > 0 && small < arr[low-1]) {
      low--;
    }
    while(high < arr.size()-1 && large > arr[high+1]) {
      high++;
    }
    return high-low+1;
  }
};
