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
    int maxdepth(TreeNode* root, unordered_map<TreeNode* , int> & mp,int &h){
        if(root==NULL){
            mp[root]=0;
            return mp[root];
        }
        else if(root->left==NULL && root->right==NULL){
            mp[root]=1;
            return mp[root];
        }
        mp[root]= 1+ max(maxdepth(root->left,mp,h),maxdepth(root->right,mp,h));
        h= max(h,mp[root->left]+ mp[root->right]);
        return mp[root];
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        int h=0;
        int j= maxdepth(root,mp,h);
        return h;

    }
};
