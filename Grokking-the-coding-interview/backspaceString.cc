using namespace std;

#include <iostream>
#include <string>

class Solution {
public:
  static bool compare(const string &str1, const string &str2) {
    // TODO: Write your code here
    int p1 = str1.size()-1;
    int p2 = str2.size()-1;
    while(p1 >= 0 && p2 >= 0) {
      if(str1[p1] == '#') {
        int backspaces = 1;
        p1--;
        while(backspaces >= 0) {
          if(str1[p1] == '#') {
            backspaces++;
          } else if (backspaces > 0) {
            backspaces--;
          } else {
            break;
          }
          p1--;
        }
      }
      if(str2[p2] == '#') {
        int backspaces = 1;
        p2--;
        while(backspaces >= 0) {
          if(str2[p2] == '#') {
            backspaces++;
          } else if (backspaces > 0) {
            backspaces--;
          } else {
            break;
          }
          p2--;
        }
      }
      if(p1 < 0 && p2 < 0) {
        return true;
      } else if (p1 < 0 || p2 < 0) {
        return false;
      }
      if(str1[p1] != str2[p2]) {
        return false;
      }
      p1--;
      p2--;
    }
    return true;
  }
};
