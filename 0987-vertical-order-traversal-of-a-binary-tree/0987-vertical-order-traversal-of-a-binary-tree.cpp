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
        map<int, map<int, multiset<int>>> mp;
        //{root},{col,row}.......
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int col = front.second.first;
            int row = front.second.second;
            mp[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({{node->right}, {col + 1, row + 1}});
        }
        // now ham ab ans ko build karenge
        for (auto& colPair : mp) {
            vector<int> temp;

            for (auto& rowPair : colPair.second) {
                temp.insert(temp.end(), rowPair.second.begin(),
                            rowPair.second.end());
            }

            ans.push_back(temp);
        }
        return ans;
    }
};