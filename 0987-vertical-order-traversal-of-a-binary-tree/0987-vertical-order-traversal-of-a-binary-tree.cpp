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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); //{ node,col,row}
        while (!q.empty()) {
            auto node = q.front().first;
            auto col = q.front().second.first;
            auto row = q.front().second.second;
            q.pop();
            mp[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }
        for (auto row : mp) {
            vector<int> temp;
            for (auto col : row.second) {
                for (auto val : col.second) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};