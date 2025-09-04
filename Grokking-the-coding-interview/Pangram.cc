#include<iostream>
using namespace std;

class Solution {
  public:
    bool checkIfPangram(string sentence) {
      // TODO: Write your code here
      std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
      for(int i = 97; i < 123; i++) {
        if(sentence.find(char(i)) == string::npos) {
          return false;
        }
      }
      return true;
    }
};