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
    TreeNode* build(vector<int>& pre, int start,int end)
    {
        cout<<start<<" "<<end<<endl;
        if(start>end){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(pre[start]);
        
        if(start==end){
            return root;
        }
        
        int idx=start+1;
        while(idx <= end && pre[idx]<pre[start]){
            idx++;
        }
        
        root->left=build(pre,start+1,idx-1);
        root->right=build(pre,idx,end);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,0,preorder.size()-1);
    }
};