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
    int dia=0;
    int height(TreeNode* root)
    {
        if(root==NULL){
            return -1;
        }
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        dia=max(dia,lh+rh+2);
        
        return max(lh,rh)+1;
    }    
    int diameterOfBinaryTree(TreeNode* root) {
        int h=height(root);
        return dia;
    }
};