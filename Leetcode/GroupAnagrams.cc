#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

class GroupAnagrams {
public:
    vector<vector<string>> Solutions(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;

        for(auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if(map.count(temp)) {
                vector<string> vec = map[temp];
                vec.push_back(s);
                map[temp] = vec;
            } else {
                vector<string> vec;
                vec.push_back(s);
                map[temp] = vec;
            }
        }

        for(auto i = map.begin(); i != map.end(); ++i) {
            res.push_back(i->second);
        }

        return res;
    }
};