
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  vector<int> findStringAnagrams(const string &str, const string &pattern)
  {
    vector<int> resultIndices;
    // TODO: Write your code here
    unordered_map<char, int> init;
    for(char c : pattern) {
      init[c]++;
    }
    int start = 0;
    int matched = 0;
    for(int end = 0; end < str.size(); end++) {
      if(init.find(str[end]) != init.end()) {
        init[str[end]]--;
        if(init[str[end]] == 0) {
          matched++;
        }
      }
      if(matched == init.size()) {
        resultIndices.push_back(start);
      }
      if(end >= pattern.size()-1) {
        if(init.find(str[start]) != init.end()) {
          if(init[str[start]] == 0){
            matched--;
          }
          init[str[start]]++;
        }
        start++;
      }
    }
    return resultIndices;
  }
};

