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
    int cnt(TreeNode* root,int mx){
        if(root==NULL){
            return 0;
        }
        if(root->val >= mx){
            int leftcount= cnt(root->left,root->val);
            int rightcount= cnt(root->right, root->val);
            return 1+ leftcount + rightcount;
        }
        int leftcount= cnt(root->left, mx);
        int rightcount= cnt(root->right,mx);
        return leftcount+ rightcount;
    }
    int goodNodes(TreeNode* root) {
        return cnt(root, root->val);
    }
};
