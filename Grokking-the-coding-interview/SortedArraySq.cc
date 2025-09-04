using namespace std;
#include <iostream> 
#include <vector>

class Solution {
public:

  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int p1 = 0;
    int p2 = arr.size()-1;
    for(int i = 0; i < arr.size(); i++) {
      int p1sq = arr[p1]*arr[p1];
      int p2sq = arr[p2]*arr[p2];
      if(p1sq >= p2sq) {
        squares[arr.size()-1-i] = p1sq;
        p1++;
      } else {
        squares[arr.size()-1-i] = p2sq;
        p2--;
      }
    }
    return squares;
  }
};
