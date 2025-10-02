using namespace std;

#include <iostream>
#include <vector>

/*class Interval {
public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};*/

class Solution {
public:
  vector<Interval> merge(const vector<Interval> &arr1, 
                                const vector<Interval> &arr2) {
    vector<Interval> result;
    // TODO: Write your code here
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
      if(arr1[i].end < arr2[j].start) {
        i++;
      } else if (arr1[i].start > arr2[j].end) {
        j++;
      } else {
        int start = max(arr1[i].start, arr2[j].start);
        int end = min(arr1[i].end, arr2[j].end);
        result.push_back(Interval(start, end));
        if(max(arr1[i].end, arr2[j].end) == arr1[i].end) {
          j++;
        } else {
          i++;
        }
      }
    }
    return result;
  }
};

