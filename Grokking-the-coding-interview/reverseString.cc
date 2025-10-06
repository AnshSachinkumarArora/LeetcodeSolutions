#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {

public: 
string reverseString(string s) {
    // ToDo: Write Your Code Here.
    string res = "";
    stack<char> stk;
    for(char c : s) {
        stk.push(c);
    }
    while(!stk.empty()) {
        char c = stk.top();
        stk.pop();
        res += c;
    }
    return res;
}
};
