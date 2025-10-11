using namespace std;

#include <iostream>
#include <vector>

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
  vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    // TODO: Write your code here
    vector<int> small;
    total(root, 0, sum, small, allPaths);
    return allPaths;
  }

  static void total(TreeNode *root, int sum, int goal, vector<int> &small, 
    vector<vector<int>> &big) {
    if(root == nullptr) {
      return;
    }

    sum += root->val;
    small.push_back(root->val);

    if(sum == goal && root->left == nullptr && root->right == nullptr) {
      big.push_back(small);
    } else {
      total(root->left, sum, goal, small, big);
      total(root->right, sum, goal, small, big);
    }

    small.pop_back();
  }
};

