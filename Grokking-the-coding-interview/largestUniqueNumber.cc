#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int maxUnique = -1;
        // ToDo: Write Your Code Here.
        unordered_map<int, int> map;
        for(int i : A) {
            map[i]++;
        }
        for(auto i : map) {
            if(i.second == 1) {
                maxUnique = max(maxUnique, i.first);
            }
        }
        return maxUnique;
    }
};

