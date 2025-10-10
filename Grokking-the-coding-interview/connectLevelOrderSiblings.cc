#include <queue>
using namespace std;

// class TreeNode {
// public:
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode *next;

//   TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
// };

class Solution {
public:
  TreeNode* connect(TreeNode* root) {
    // TODO: Write your code here
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      int levelSize = q.size();
      TreeNode* prev = q.front();
      q.pop();
      for(int i = 1; i <= levelSize; i++) {
        if(prev->left != nullptr) q.push(prev->left);
        if(prev->right != nullptr) q.push(prev->right);
        if(i == levelSize) {
          prev->next = nullptr;
          break;
        };
        TreeNode* current = q.front();
        q.pop();
        prev->next = current;
        prev = current;
      }
    }
    return root;
  }
};

