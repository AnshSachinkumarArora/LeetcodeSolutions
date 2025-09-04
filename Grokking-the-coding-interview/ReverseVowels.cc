#include <iostream>
#include <string>
#include <map>

class Solution {
  public:
  
    std::string reverseVowels(std::string s) {
      // TODO: Write your code here
      string vowels = "AEIOUaeiou";
      map<int, char> um;
      for (int i = 0; i < s.length(); i++) {
        if (vowels.find(s[i]) != string::npos) {
          um.insert({i, s[i]});
        }
      }
      for(auto it = um.begin(); it != um.end(); it++) {
        auto last = um.rbegin();
        if(last->first == it->first) {
          continue;
        }
        s[it->first] = last->second;
        s[last->first] = it->second;
        um.erase(last->first);
      }
      return s;
    }
};
