#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSubarrays(vector<int>& nums, int target) {
        int totalCount = 0;
        // ToDo: Write Your Code Here.
        int start = 0;
        int counter = 0;
        int currMult = 1;
        for(int end = 0; end < nums.size(); end++) {
            currMult *= nums[end];
            while(start <= end && currMult >= target) {
                if(currMult < target) {
                    totalCount++;
                }
                currMult /= nums[start++];
            }
            totalCount += end-start+1;
        }
        
        // Return the result.
        return totalCount;
    }
};


