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
    vector<TreeNode*> traverse(TreeNode* root,int k, vector<TreeNode*>& temp)
    {
        
        vector<TreeNode*> output;
        if(root==NULL){
            return output;
        }
        
        if(root->val==k){
            temp.push_back(root);
            return temp;
        }
        
        temp.push_back(root);
        vector<TreeNode*> left=traverse(root->left,k,temp);
        if(left.size()>0){
            return left;
        }
        else
        {
            vector<TreeNode*> right=traverse(root->right,k,temp);
            if(right.size()>0){
                return right;
            }
            else
            {
                temp.pop_back();
                return output;
            }   
        }
    }
    vector<TreeNode*> nodeToRoot(TreeNode* root,int k)
    {
        vector<TreeNode*> temp;
        return traverse(root,k,temp);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath=nodeToRoot(root,p->val);
        vector<TreeNode*> qPath=nodeToRoot(root,q->val);
        
        int i=0;
        while(i< pPath.size() && i< qPath.size() && pPath[i]==qPath[i]){
            i++;
        }
        
        return pPath[i-1];
    }
};