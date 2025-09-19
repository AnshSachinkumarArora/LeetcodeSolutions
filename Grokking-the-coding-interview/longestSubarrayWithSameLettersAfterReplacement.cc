using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int findLength(const string &str, int k)
    {
      if(k == str.size()) {
        return str.size();
      }
      int maxLength = 0;
      // TODO: Write your code here
      int topFreq = 0;
      int start = 0;
      unordered_map<char, int> map;
      for(int end = 0; end < str.size(); end++) {
        map[str[end]]++;
        topFreq = max(topFreq, map[str[end]]);
        while(end-start+1-topFreq > k) {
          map[str[start]]--;
          start++;
        }
        maxLength = max(maxLength, end-start+1);
      }
      return maxLength;
    }
};

