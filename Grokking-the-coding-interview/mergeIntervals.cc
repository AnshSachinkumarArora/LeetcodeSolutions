using namespace std;

#include <algorithm>
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
  bool comp(Interval &a, Interval &b) {
    return a.start < b.start;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    if(intervals.size() < 2) {
      return intervals;
    }
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    sort(intervals.begin(), intervals.end(), 
    [](const Interval &x, const Interval &y) { return x.start < y.start; });
    int start = intervals[0].start, end = intervals[0].end;
    for(int i = 1; i < intervals.size(); i++) {
      cout<<start<<endl;
      cout<<end<<endl;
      if(intervals[i].start >= start && intervals[i].start <= end) {
        end = max(end, intervals[i].end);
      } else {
        mergedIntervals.push_back(Interval(start, end));
        start = intervals[i].start;
        end = intervals[i].end;
      }
      if(i == intervals.size()-1) {
        mergedIntervals.push_back(Interval(start, end));
      }
    }
    return mergedIntervals;
  }
};

