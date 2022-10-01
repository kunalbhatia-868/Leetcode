/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA=NULL;
    
    bool helperLca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL){
            return false;
        }
        
        bool self=p==root || q==root;
        bool left=helperLca(root->left,p,q);
        bool right=helperLca(root->right,p,q);
        
        if((self  && left) || (self && right) || (left && right))
        {
            LCA=root;
        }
        return self || left || right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool ans=helperLca(root,p,q);
        return LCA;    
    }
};