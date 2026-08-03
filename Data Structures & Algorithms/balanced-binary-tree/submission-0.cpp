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
    int maxdepth(TreeNode* root,unordered_map<TreeNode* ,int > &mp){
        if(root==NULL){
            return mp[root]=0;
        }
        else if(root->left ==NULL && root->right==NULL){
            return mp[root]=1;
        }
        return mp[root]=1+ max(maxdepth(root->left,mp),maxdepth(root->right,mp));
    }

    bool isBalanced(TreeNode* root) {
        
        unordered_map<TreeNode* ,int> mp;
        maxdepth(root,mp);
        stack<TreeNode*> st;

        if(root==NULL){
            return true;
        }
        st.push(root);
        while(!st.empty()){
            TreeNode* node= st.top();
            st.pop();
            int l= mp[node->left];
            int r= mp[node->right];
            
            if(abs(l-r)<=1){
                
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
            }
            else{
            return false;}
        }
        return true;
        
    }
};
