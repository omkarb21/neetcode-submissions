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
    void findGoodNodes(TreeNode* root, int& count, int maxTillNow){
        

        if(root){
            if(maxTillNow<=root->val){
                count++;
            }
            maxTillNow=max(maxTillNow,root->val);
        }
        else return;

        findGoodNodes(root->left,count,maxTillNow);
        findGoodNodes(root->right,count,maxTillNow);


    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxTillNow=INT_MIN;
        findGoodNodes(root,count,maxTillNow);
        return count;
    }
};
