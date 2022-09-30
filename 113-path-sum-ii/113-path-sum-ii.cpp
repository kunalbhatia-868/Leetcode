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
    void pathSum(TreeNode* root, int targetSum,vector<int> temp,vector<vector<int>>& output)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==root->val)
            {
                temp.push_back(root->val);
                output.push_back(temp);
            }
            return;
        }
        
        temp.push_back(root->val);
        pathSum(root->left,targetSum-root->val,temp,output);
        pathSum(root->right,targetSum-root->val,temp,output);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> temp;
        pathSum(root,targetSum,temp,output);
        return output;
    }
};