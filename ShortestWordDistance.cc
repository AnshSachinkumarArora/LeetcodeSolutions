#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    // TODO: Write your code here
    int shortestDistance = 1e9;
    int p1;
    int p2;
    for(int i = 0; i < words.size(); i++) {
      if(words[i] == word1) {
        p1 = i;
      } else if (words[i] == word2) {
        p2 = i;
      }
      int temp = abs(p1-p2);
      if(temp < shortestDistance) {
        shortestDistance = temp;
      }
    }
    return shortestDistance;
  }
};