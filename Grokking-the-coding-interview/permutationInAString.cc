
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool findPermutation(const string &str, const string &pattern)
    {
        // TODO: Write your code here
        unordered_map<char, int> init;
        for(char c : pattern) {
            init[c]++;
        }
        int start = 0;
        for(int end = 0; end < str.size(); end++) {
            if(init.find(str[end]) != init.end()) {
                int temp = end;
                start = end;
                unordered_map<char, int> test;
                bool didBreak = false;
                while(temp-end+1 <= pattern.size() && init.find(str[temp]) != init.end()) {
                    test[str[temp]]++;
                    if(test[str[temp]] > init[str[temp]]) {
                        didBreak = true;
                        break;
                    }
                    temp++;
                }
                if(temp-end ==  pattern.size() && didBreak == false) {
                    return true;
                }
            }
        }
        return false;
    }
};

