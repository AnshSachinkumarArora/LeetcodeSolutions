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
  static bool hasPath(TreeNode *root, int sum) {
    // TODO: Write your code here
    int res = total(root, 0, sum);

    if(res == sum) {
      return true;
    }

    return false;
  }

  static int total(TreeNode *root, int sum, int goal) {
    if(root == nullptr) {
      return 0;
    }

    sum += root->val;

    if(root->left == nullptr && root->right == nullptr) {
      return sum;
    }

    int leftVal = total(root->left, sum, goal);
    int rightVal = total(root->right, sum, goal);

    if(leftVal == goal || rightVal == goal) {
      return goal;
    } else {
      return INT_MIN;
    }
  } 
};

