using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int findLength(const string &str, int k)
    {
        int start = 0, maxLength = 0;
        unordered_map<char, int> unique;
        // TODO: Write your code here
        for(int end = 0; end < str.size(); end++) {
            unique[str[end]]++;
            while(unique.size() > k) {
                unique[str[start]]--;
                if(unique[str[start]] <= 0) {
                    unique.erase(str[start]);
                }
                start++;
            }
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};
