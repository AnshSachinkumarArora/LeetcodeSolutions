using namespace std;

#include <iostream>

/*class TreeNode {
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};*/

class Solution {
public:
  int findSumOfPathNumbers(TreeNode *root) {
    // TODO: Write your code here
    string start = "";
    int res = helper(root, 0, start);
    return res;
  }

  int helper(TreeNode *root, int sum, string &num) {
    if(root == nullptr) {
      return sum;
    }
    num += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr) {
      sum += stoi(num);
    } else {
      int leftSum = helper(root->left, sum, num);
      int rightSum = helper(root->right, sum, num);
      sum = leftSum + rightSum;
    }
    num.pop_back();
    return sum;
  }
};

