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
    TreeNode* build(vector<int>& pre, int preStart, int preEnd,vector<int>& post,int postStart,int postEnd)
    {
        
        if(preStart>preEnd){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(pre[preStart]);
        
        if(preStart==preEnd){
            return root;
        }
        
        int idx=postStart;
        while(post[idx]!=pre[preStart+1])
        {
            idx++;
        }
        
        int newPreSize=idx-postStart+1;
        
        
        root->left=build(pre,preStart+1,preStart+newPreSize,post,postStart,idx);
        root->right=build(pre,preStart+newPreSize+1,preEnd,post,idx+1,postEnd-1);
        
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    
    }
};