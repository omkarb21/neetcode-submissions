/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int findMaxSum(TreeNode* root, int& ansMax) {
        if (!root) return 0;

        int leftMax  = max(0, findMaxSum(root->left, ansMax));
        int rightMax = max(0, findMaxSum(root->right, ansMax));

        // best path that bends at this node
        ansMax = max(ansMax, root->val + leftMax + rightMax);

        // best path that can continue up to the parent (one side only)
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int ansMax = INT_MIN;
        findMaxSum(root, ansMax);
        return ansMax;
    }
};
