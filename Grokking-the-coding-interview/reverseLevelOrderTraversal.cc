using namespace std;

#include <deque>
#include <iostream>
#include <queue>

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
  vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    // TODO: Write your code here
    if(root == nullptr) {
      return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      int levelSize = q.size();
      vector<int> level;
      for(int i = 0; i < levelSize; i++) {
        level.push_back(q.front()->val);
        if(q.front()->left != nullptr) q.push(q.front()->left);
        if(q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
      }
      result.push_back(level);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

