using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size()-3; i++) {
      if (i > 0 && arr[i] == arr[i-1]) {
        continue;
      }
      for(int j = i+1; j < arr.size()-2; j++) {
        if(j > i + 1 && arr[j] == arr[j-1]) {
          continue;
        }
        int currSum = arr[i]+arr[j];
        int l = j+1;
        int r = arr.size()-1;
        while(l < r) {
          if(arr[l]+arr[r]+currSum == target) {
            quadruplets.push_back({arr[i], arr[l], arr[j], arr[r]});
            l++;
            r--;
            while(l < r && arr[l] == arr[l-1]) {
              l++;
            }
            while(l < r && arr[r] == arr[r+1]) {
              r--;
            }
          } else if (arr[l]+arr[r]+currSum > target) {
            r--;
          } else {
            l++;
          }
        }
      }
    }
    return quadruplets;
  }
};
