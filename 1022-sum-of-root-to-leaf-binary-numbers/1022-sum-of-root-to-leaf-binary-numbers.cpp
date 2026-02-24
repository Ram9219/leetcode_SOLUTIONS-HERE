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
    int sumRootToLeaf(TreeNode* root,int current=0) {
        if(root==NULL)return 0;

        current=current*2+root->val;
        if(root->left==NULL && root->right==NULL){
            return current;
        }
        return sumRootToLeaf(root->left,current)+sumRootToLeaf(root->right,current);
        
    }
};