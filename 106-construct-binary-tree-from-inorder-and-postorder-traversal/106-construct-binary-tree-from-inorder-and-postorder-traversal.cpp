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
    TreeNode* build(vector<int>& post,int ps,int pe,vector<int>& in, int is, int ie)
    {
        if(ps>pe){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(post[pe]);
        
        int idx=is;
        while(in[idx]!=post[pe])
        {
            idx++;
        }
        
        int postSize=idx-is;
        
        root->left=build(post,ps,ps+postSize-1,in,is,idx-1);
        root->right=build(post,ps+postSize,pe-1,in,idx+1,ie);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }
};