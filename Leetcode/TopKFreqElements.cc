#include <unordered_map>
#include <vector>

class TopKFreqElements {
public:
    vector<int> solution(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        vector<vector<int>> vec(nums.size()+1);

        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }

        for(auto i = map.begin(); i != map.end(); ++i) {
            vec[i->second].push_back(i->first);
        }

        for(int i = vec.size()-1; i >= 0; --i) {
            if(res.size() >= k) {
                return res;
            } else if (!vec[i].empty()) {
                copy(vec[i].begin(), vec[i].end(), back_inserter(res));
            }
        }

        return res;
    }
};