using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<int> sort(vector<int> &arr) {
    // TODO: Write your code here
    int p1 = 0;
    int p2 = arr.size()-1;
    for(int i = 0; i <= p2;) {
      if(arr[i] == 0) {
        int temp = arr[i];
        arr[i] = arr[p1];
        arr[p1] = temp;
        p1++;
        i++;
      } else if (arr[i] == 2) {
        int temp = arr[i];
        arr[i] = arr[p2];
        arr[p2] = temp;
        p2--;
      } else {
        i++;
      }
    }
    return arr;
  }
};
