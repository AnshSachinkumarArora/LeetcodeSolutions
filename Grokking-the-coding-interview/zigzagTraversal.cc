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
    queue<TreeNode*> q;
    q.push(root);
    int levelNum = 0;
    while(!q.empty()) {
      int levelSize = q.size();
      vector<int> level(levelSize);
      for(int i = 0; i < levelSize; i++) {
        TreeNode *curr = q.front();
        q.pop();
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
        if(levelNum % 2 == 1) {
          level[levelSize-i-1] = curr->val;
        } else {
          level[i] = curr->val;
        }
      }
      result.push_back(level);
      levelNum++;
    }
    return result;
  }
};

