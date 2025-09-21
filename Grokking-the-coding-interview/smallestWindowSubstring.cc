
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    string findSubstring(const string &str, const string &pattern)
    {
      // TODO: Write your code here
      unordered_map<char, int> pat;
      for(char c : pattern) {
        pat[c]++;
      }
      int start = 0;
      int minlen = str.size()+1;
      int matched = 0;
      int substart = 0;
      for(int end = 0; end < str.size(); end++) {
        if(pat.find(str[end]) != pat.end()) {
          pat[str[end]]--;
          if(pat[str[end]] >= 0) {
            matched++;
          }
        }
        while(matched == pattern.size()) {
          if(minlen > end-start+1) {
            minlen = end-start+1;
            substart = start;
          }
          char left = str[start++];
          if (pat.find(left) != pat.end()) {
            if(pat[left] == 0) {
              matched--;
            }
            pat[left]++;
          }
        }
      }
      if(minlen > str.size()) {
        return "";
      }
      return str.substr(substart, minlen); 
    }
};

