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
    
    void preOrder(TreeNode* root,vector<int> &output)
    {
        if(root==NULL){
            return;
        }
        
        output.push_back(root->val);
        preOrder(root->left,output);
        preOrder(root->right,output);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        preOrder(root,output);
        return output;
    }
};