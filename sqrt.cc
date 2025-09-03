#include <iostream>

class Solution {
public:
  int mySqrt(int x) {
    int res;
    if(x<=1) {
      return x;
    }
    int l = 2;
    int r = x/2;
    while(l <= r) {
      int m = l+(r-l)/2;
      long sqr = (long)m*m;
      if(sqr>x) {
        r = m-1;
      } else if(sqr<x) {
        l = m+1;
      } else {
        return m;
      }
    }
    return r;
  }
};