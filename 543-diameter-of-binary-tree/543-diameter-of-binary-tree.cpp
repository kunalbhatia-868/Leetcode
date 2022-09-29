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
    pair<int,int> diameterHeight(TreeNode* root)
    {
        if(root==NULL){
            return {0,-1};
        }
        
        pair<int,int> left=diameterHeight(root->left);
        pair<int,int> right=diameterHeight(root->right);

        int ld=left.first;
        int rd=right.first;
        int lh=left.second;
        int rh=right.second;
            
        int fd=max(lh+rh+2,max(ld,rd));
        int fh=max(lh,rh)+1;
        pair<int,int> output={fd,fh};
        return output;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans=diameterHeight(root);
        return ans.first;
    }
};