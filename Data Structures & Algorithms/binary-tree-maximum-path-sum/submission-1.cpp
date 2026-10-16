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
    int findMaxSum(TreeNode* root,int& ansMax){
        if(!root) return 0;

        int leftMax=findMaxSum(root->left,ansMax);
        int rightMax=findMaxSum(root->right,ansMax);

        ansMax=max(ansMax,leftMax+root->val);
        ansMax=max(ansMax,rightMax+root->val);
        ansMax=max(ansMax,root->val);
        ansMax=max(ansMax,leftMax+rightMax+root->val);

        return max(root->val,root->val+max(leftMax,rightMax));
    } 
    int maxPathSum(TreeNode* root) {
        int ansMax=INT_MIN;
        
        int temp=findMaxSum(root,ansMax);
        return ansMax;
    }
};
