
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    vector<int> findWordConcatenation(const string &str,
                                            const vector<string> &words)
    {
      vector<int> resultIndices;
      // TODO: Write your code here
      if(words.size() == 0 || words[0].size() == 0 || str.size() < words.size()*words[0].size()) {
        return resultIndices;
      }
      int wordLen = words[0].size();
      unordered_map<string, int> freqMap;
      for(string s : words) {
        freqMap[s]++;
      }
      for(int end = 0; end <= int(str.size())-(words.size()*wordLen); end++) {
        unordered_map<string, int> seen;
        for(int j = 0; j < words.size(); j++) {
          string word = str.substr(end+j*wordLen, wordLen);
          if(freqMap.find(word) == freqMap.end()) {
            break;
          }
          seen[word]++;
          if(seen[word] > freqMap[word]) {
            break;
          }
          if(j+1 == words.size()) {
            resultIndices.push_back(end);
          }
        }
      }
      return resultIndices;
    }
};

