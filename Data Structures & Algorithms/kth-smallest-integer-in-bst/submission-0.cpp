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
    void dfs(TreeNode* root, priority_queue<int> & pq,int k){
        if(root==NULL){
            return ;
        }
        pq.push(root->val);
        while(pq.size()>k){
            pq.pop();
        }
        if(root->left){
            dfs(root->left,pq,k);
        }
        if(root->right){
            dfs(root->right,pq,k);
        }
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root, pq,k);
        return pq.top();
    }
};
