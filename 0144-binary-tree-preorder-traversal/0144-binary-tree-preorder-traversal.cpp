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
//i am using stack here and what ios the idea to store the root on top pront then and if right and left push right and left then left will be on the top 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            //right
            if(root->right!=NULL)st.push(root->right);
            //left
            if(root->left!=NULL)st.push(root->left);
            //store the top first value which follow the NLR
            ans.push_back(root->val);
        }
        return ans;
    }
};