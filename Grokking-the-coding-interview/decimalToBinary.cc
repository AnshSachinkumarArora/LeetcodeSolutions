#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
string decimalToBinary(int num) {
    // ToDo: Write Your Code Here.
    stack<int> s;
    int remainder = num%2;
    int quotient = num/2;
    int dividend = quotient;
    s.push(remainder);
    while(quotient > 0) {
        quotient = dividend/2;
        remainder = dividend%2;
        dividend = quotient;
        s.push(remainder);
    }
    string res = "";
    while(!s.empty()) {
        res += to_string(s.top());
        s.pop();
    }
    return res;
}
};
