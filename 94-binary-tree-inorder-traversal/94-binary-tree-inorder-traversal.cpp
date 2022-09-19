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
    void inOrder(TreeNode* root,vector<int> &output)
    {
        if(root==NULL){
            return;
        }
        
        
        inOrder(root->left,output);
        output.push_back(root->val);
        inOrder(root->right,output);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inOrder(root,output);
        return output;
    }
};