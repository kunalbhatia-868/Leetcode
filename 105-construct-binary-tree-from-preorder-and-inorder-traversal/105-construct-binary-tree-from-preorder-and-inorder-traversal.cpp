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
    TreeNode* build(vector<int>& pre,int ps,int pe,vector<int>& in,int is,int ie)
    {      
        
        if(is>ie){
            return NULL;
        }

        TreeNode* root=new TreeNode(pre[ps]);
        
        int centerIndex=is;
        while(in[centerIndex]!=pre[ps]){
            centerIndex++;
        }
        
        int preSize=centerIndex-is;
        int newLPs=ps+1;
        int newLPe=ps+preSize;
        int newRPs=ps+preSize+1;
        int newRPe=pe;
         
        root->left=build(pre,newLPs,newLPe,in,is,centerIndex-1);
        root->right=build(pre,newRPs,newRPe,in,centerIndex+1,ie);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};