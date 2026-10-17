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
    int findMaxSum(TreeNode* root,int& sumAns){
        if(!root) return 0;



        int leftAns=findMaxSum(root->left,sumAns);
        int rightAns=findMaxSum(root->right,sumAns);

        sumAns=max({sumAns,root->val,root->val+leftAns,root->val+rightAns,root->val+leftAns+rightAns});

        return max({root->val,root->val+leftAns,root->val+rightAns});


    }
    int maxPathSum(TreeNode* root) {
        int sumAns=INT_MIN;
        findMaxSum(root,sumAns);
        return sumAns;
    }
};
