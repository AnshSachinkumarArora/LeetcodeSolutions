using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinSubArray(int S, const vector<int>& arr) {
      // TODO: Write your code here
      int smallest = arr.size();

      //naive solution
      /*vector<int> sumArr(arr.size());
      vector<int> sizeArr(arr.size());
      bool maxHit = false;
      for(int end = 0; end < arr.size(); end++) {
        sumArr[end] += arr[end];
        sizeArr[end]++;
        if(sumArr[end] >= S) {
          smallest = min(smallest, sizeArr[end]);
          return 1;
        }
        for(int i = 0; i < end; i++) {
          if(sumArr[i] < S) {
            sumArr[i] += arr[end];
            sizeArr[i]++;
          }
          if(sumArr[i] >= S) {
            smallest = min(smallest, sizeArr[i]);
            maxHit = true;
          }
        }
      }
      if(smallest == arr.size() && maxHit == false) {
        smallest = 0;
      }*/

      //Optimal solution
      int start = 0;
      int sum = 0;
      int size = 0;
      bool maxHit = false;
      for(int end = 0; end < arr.size(); end++) {
        if(arr[end] >= S) {
          return 1;
        }
        sum += arr[end];
        size++;
        while(sum >= S) {
          maxHit = true;
          smallest = min(smallest, size);
          sum -= arr[start];
          start++;
          size--;
        }
      }
      if(smallest == arr.size() && maxHit == false) {
        return 0;
      }
      return smallest;
    }
  };
