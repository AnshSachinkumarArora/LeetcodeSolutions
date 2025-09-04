using namespace std;

#include <iostream>
#include <vector>

class Solution {

  public:

  static vector<int> search(const vector<int> &arr, int targetSum) {
    // TODO: Write your code here
    vector<int> res = {-1,-1};
    int p1 = 0;
    int p2 = arr.size()-1;
    while(p1<p2) {
      if(arr[p1]+arr[p2] < targetSum) {
        p1++;
      } else if(arr[p1]+arr[p2] > targetSum) {
        p2--;
      } else {
        res[0] = p1;
        res[1] = p2;
        return res;
      }
    }
    return vector<int>(2, -1);
  }

};
