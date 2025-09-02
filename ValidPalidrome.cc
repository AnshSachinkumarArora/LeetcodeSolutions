#include <iostream>

class Solution {
public:
  bool isPalindrome(std::string s) {
    // TODO: Write your code here
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::string res = "";
    for(auto ch : s) {
      if(std::isalpha(ch) || std::isdigit(ch)) {
        res += ch;
      }
    }
    for(int i = 0; i < res.size(); i++) {
      if (res[i] != res[res.size()-1-i]) {
        return false;
      }
    }
    return true;
  }
};