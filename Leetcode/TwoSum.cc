#include <unordered_map>
#include <iostream>
#include <vector>

class TwoSum {
public:
    vector<int> solution(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        if (nums.size() == 2) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] *= -1;
            int temp = target + nums[i];
            if(map.count(temp)) {
                if(map[temp] != i) {
                    res.push_back(i);
                    res.push_back(map[temp]);
                    return res;
                }
            }
        }

        return res;
    }
};