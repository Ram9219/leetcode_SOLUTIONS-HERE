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
    vector<string> ans;

    void preorder(TreeNode* root, string path) {
        if (root == NULL) return;

        path += to_string(root->val);

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";
        preorder(root->left, path);
        preorder(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root, "");
        return ans;
    }
};
