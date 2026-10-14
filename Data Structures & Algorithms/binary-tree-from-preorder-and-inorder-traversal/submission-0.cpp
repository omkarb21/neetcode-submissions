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
    int findIndexInOrder(vector<int>& inorder, int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)return i;
        }
        return -1;
    }
    TreeNode* myBuildTree(vector<int>&preorder,vector<int>& inorder, int& preOrderIndex, int inOrderStartIndex, int inOrderEndIndex){
        if(preOrderIndex>=preorder.size()) return NULL;

        if(inOrderStartIndex>inOrderEndIndex) return NULL;

        TreeNode* root=new TreeNode(preorder[preOrderIndex]);
        int indexInOrder=findIndexInOrder(inorder, preorder[preOrderIndex]);
        preOrderIndex++;
        root->left=myBuildTree(preorder,inorder, preOrderIndex, inOrderStartIndex, indexInOrder-1);
        root->right=myBuildTree(preorder,inorder, preOrderIndex, indexInOrder+1, inOrderEndIndex);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int inOrderStartIndex=0;
        int inOrderEndIndex=inorder.size()-1;

        return myBuildTree(preorder,inorder, preOrderIndex,inOrderStartIndex,inOrderEndIndex);
    }
};
