using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) {
      if(i > 0 && arr[i] == arr[i-1]) {
        continue;
      }
      int p1 = i+1; 
      int p2 = arr.size()-1;
      while(p1 < p2) {
        int diff = arr[p1]+arr[p2];
        if (diff < -arr[i]) {
          p1++;
        } else if (diff > -arr[i]) {
          p2--;
        } else {
          vector<int> res = {arr[i], arr[p1], arr[p2]};
          triplets.push_back(res);
          p1++;
          p2--;
          while(p1 < p2 && arr[p1] == arr[p1-1]) {
            p1++;
          }
          while(p1 < p2 && arr[p2] == arr[p2+1]) {
            p2--;
          }
        }
      }
    }
    return triplets;
  }
};
