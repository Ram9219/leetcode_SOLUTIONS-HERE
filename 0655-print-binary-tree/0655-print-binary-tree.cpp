/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode* root, vector<vector<string>>& ans, int row, int left,
             int right) {
        if (!root || left > right) {
            return;
        }
        int mid = (left + right) / 2;
        ans[row][mid] = to_string(root->val);
        dfs(root->left, ans, row + 1, left, mid - 1);
        dfs(root->right, ans, row + 1, mid + 1, right);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        // dfs apply karna hoga wo bhi grid ke format me ans ko laana hoga
        // aur then fir print karna hoga
        int h = height(root);
        int row = h;
        int col = (1 << h) - 1;
        vector<vector<string>> ans(row, vector<string>(col, ""));
        dfs(root, ans, 0, 0, col - 1);
        return ans;
    }
};