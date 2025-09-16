using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    int findLength(const vector<char> &arr)
    {
        int maxLength = 0;
        int currMax = 0;
        int start = 0;
        unordered_map<char, int> unique;
        for(int end = 0; end < arr.size(); end++) {
            unique[arr[end]]++;
            maxLength++;
            while(unique.size() > 2) {
                unique[arr[start]]--;
                if (unique[arr[start]] <= 0) {
                    unique.erase(arr[start]);
                }
                maxLength--;
                start++;
            };
            currMax = max(currMax, maxLength);
        }
        // TODO: Write your code here
        return currMax;
    }
};
