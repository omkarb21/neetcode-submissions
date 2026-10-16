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
    vector<int> rightSideView(TreeNode* root) {
        //keep on adding roots and its children to a queue with a tracker
            //simulataneously add levelNumber and node to a hashamp
            //keep a count of max reached
        queue<pair<TreeNode*, int>>q;
        unordered_map<int,TreeNode*>mp;
        int maxLevel=INT_MIN;
        vector<int>result;

        if(!root){
            return result;
        }
        else{
            int maxLevel=0;
            q.push({root,maxLevel});
        }

        while(!q.empty()){
            auto removedNode=q.front();
            q.pop();

            TreeNode* removedNodeData=removedNode.first;
            mp[removedNode.second]=removedNode.first;
            
            maxLevel=removedNode.second;

            if(removedNodeData->left){
                q.push({removedNodeData->left,maxLevel+1});
            }
            if(removedNodeData->right){
                q.push({removedNodeData->right,maxLevel+1});
            }

        }

        for(int i=0;i<=maxLevel;i++){
            result.push_back(mp[i]->val);
        }

        return result;

        
    }
};
