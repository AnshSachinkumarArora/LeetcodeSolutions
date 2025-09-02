#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

using namespace std;

//Leetcode solution
class  ValidAnagram{
public:
    bool Solution(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        int arr[26] = {};

        for(int i = 0; i < s.size(); ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; ++i) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

//Grokking solution
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      // TODO: Write your code here
      if(s.size() != t.size()) {
        return false;
      }
      unordered_map<char, int> um1;
      unordered_map<char, int> um2;
      for(int i = 0; i < s.size(); i++) {
        um1[s[i]]++;
        um2[t[i]]++;
      }
      for(auto& k : um1) {
        if(um2.find(k.first) == um2.end() || k.second != um2[k.first]) {
          return false;
        }
      }
      return true;
    }
};