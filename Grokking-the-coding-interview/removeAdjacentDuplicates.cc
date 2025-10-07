#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // TODO: Write your code here
        vector<pair<char, int>> stack;
        for(char c : s) {
            int top = stack.size()-1;
            if(!stack.empty() && stack[top].first == c) {
                if(stack[top].second == k-1) {
                    stack.pop_back();
                } else {
                    stack[top].second++;
                }
            } else {
                stack.push_back(pair<char, int> {c, 1});
            }
        }

        string res = "";
        for(pair p : stack) {
            res.append(p.second, p.first);
        }
        return res;
    }
};
