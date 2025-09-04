#include <set>
#include <vector>

using namespace std;

class ContainsDuplicate {
public:
    bool solution(vector<int>& nums) {
        set<int> uset;
        for(int i : nums) {
            if (uset.count(i) == 0) {
                uset.insert(i);
            } else {
                return true;
            }
        }
        return false;
    }
};