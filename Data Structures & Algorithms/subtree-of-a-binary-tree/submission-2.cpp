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
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2== NULL){
            return true;
        }
        else if(root1==NULL || root2== NULL){
            return false;
        }
        else if(root1->val==root2->val){
            return isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node= st.top();
            st.pop();
            if(node->val==subRoot->val){
                
                bool check=isSame(node,subRoot);
                if(check){
                    return true;
                }
                else{
                    
                    if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
                }
            }
            else{
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
            }
        }
        return false;
    }
};
