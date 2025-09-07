using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int searchTriplets(vector<int> &arr, int target) {
    if(arr.size() < 3) {
      return 0;
    }
    int count = 0;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size()-2; i++) {
      int l = i+1;
      int r = arr.size()-1;
      while(l < r) {
        if(arr[i]+arr[l]+arr[r] < target) {
          count += r-l;
          l++;
        } else  {
          r--;
        }
      }
    }
    return count;
  }
};
