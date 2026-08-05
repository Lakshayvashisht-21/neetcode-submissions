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
    int mx= INT_MIN;
    void dfs(TreeNode* root, unordered_map<TreeNode* ,int> & mp){
        if(root==NULL){
            mp[root]=0;
            return ;
        }
        dfs(root->left,mp);
        dfs(root->right,mp);
        int check= max(mp[root->left],mp[root->right]);
        mp[root]= max(0,check) + root->val;
        return ;
    }
    void dfs2(TreeNode* root,unordered_map<TreeNode*,int>& mp){
        if(root==NULL){
            return ;
        }
        dfs2(root->left,mp);
        dfs2(root->right,mp);
        mx= max(mx,mp[root]);
        mx= max(mx, mp[root->left]+ mp[root->right]+ root->val);
        return ;
    }
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        dfs(root,mp);

        dfs2(root,mp);
        return mx;
        
    }   
};
