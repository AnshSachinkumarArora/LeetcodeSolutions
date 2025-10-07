#include <iostream>
#include <vector>
#include <deque>
#include<stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        // ToDo: Write Your Code Here.
        stack<int> s;
        long sum = 0;
        int mod = 1'000'000'007;
        for(int i = 0; i <= arr.size(); i++) {
            int currElt = (i == arr.size() ? 0 : arr[i]);
            while(!s.empty() && arr[s.top()] > currElt) {
                int min = s.top(); s.pop();
                int prev = (s.empty() ? -1 : s.top());
                int count = (min-prev) * (i-min);
                sum = (sum + (long)arr[min]*count%mod)%mod;
            }
            s.push(i);
        }
        return (int)sum%mod;
    }
};

