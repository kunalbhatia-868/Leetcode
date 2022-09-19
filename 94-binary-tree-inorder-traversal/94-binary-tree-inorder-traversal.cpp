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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if(root==NULL){
            return output;
        }
        
        stack<TreeNode*> st;
        TreeNode* curr=root;
        
        while(true)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                
                if(st.empty()){
                    break;
                }
                curr=st.top();
                st.pop();
                output.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return output;
    }
};