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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int leftHeight=1+maxDepth(root->left);
        int rightHeight=1+maxDepth(root->right);
        return max(leftHeight,rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int option1=maxDepth(root->left)+maxDepth(root->right);
        int option2=diameterOfBinaryTree(root->left);
        int option3=diameterOfBinaryTree(root->right);

        return max(option1, max(option2,option3));
    }
};
