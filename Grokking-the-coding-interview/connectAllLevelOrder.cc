using namespace std;

#include <iostream>
#include <queue>

/*class TreeNode {
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

};*/

class Solution {
public:
  TreeNode* connect(TreeNode *root) {
    //TODO: Write your code here
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* prev = nullptr;
    while(!q.empty()) {
      int levelSize = q.size();
      for(int i = 0; i < levelSize; i++) {
        TreeNode* current = q.front();
        q.pop();
        if(prev != nullptr) {
          prev->next = current;
        }
        prev = current;
        if(current->left != nullptr) q.push(current->left);
        if(current->right != nullptr) q.push(current->right);
      }
    }
    return root;
  }
};

