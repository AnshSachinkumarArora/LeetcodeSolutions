#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // ToDo: Write Your Code Here.
        if(s.size() == 1) {
            return false;
        }
        stack<char> st;
        for(char c : s) {
            if(c != '(' && c != '{' && c != '[') {
                char test = st.top();
                st.pop();
                if(test == '(' && c != ')') {
                    return false;
                } else if (test == '{' && c != '}') {
                    return false;
                } else if (test == '[' && c != ']') {
                    return false;
                } else {
                    continue;
                }
            } else {
                st.push(c);
            }
        }
        return true;
    }
};

