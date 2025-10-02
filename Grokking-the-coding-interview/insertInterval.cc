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
  vector<Interval> insert(const vector<Interval> &intervals, 
                                Interval newInterval) {
    vector<Interval> mergedIntervals;
    if(intervals.size() == 0) {
      return vector<Interval>{newInterval};
    }
    // TODO: Write your code here
    int i = 0;
    int n = intervals.size();
    while(i < n && intervals[i].end < newInterval.start) {
      mergedIntervals.push_back(intervals[i++]);
    }
    while(i < n && intervals[i].start <= newInterval.end) {
      newInterval.start = min(intervals[i].start, newInterval.start);
      newInterval.end = max(intervals[i].end, newInterval.end);
      i++;
    }
    mergedIntervals.push_back(newInterval);
    while(i < n) {
      mergedIntervals.push_back(intervals[i++]);
    }
    return mergedIntervals;
  }
};

