#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // ToDo: Write Your Code Here.
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(map.find(c) != map.end()) {
                map.erase(c);
            } else {
                map[c] = i;
            }
        }
        if(!map.empty()) {
            int lowest = s.size()+1;
            for (auto i : map) {
                lowest = min(lowest, i.second);
            }
            return lowest;
        }
        return -1;
    }
};

