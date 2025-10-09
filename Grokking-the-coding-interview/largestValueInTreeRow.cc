#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };

class Solution {

public:
    // Method to find the largest value in each row of the binary tree
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        // ToDo: Write Your Code Here.
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int level_size = q.size();
            int highest = INT_MIN;
            for(int i = 0; i < level_size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                highest = max(highest, curr->val);
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            result.push_back(highest);
        }
        return result;
    }
};

