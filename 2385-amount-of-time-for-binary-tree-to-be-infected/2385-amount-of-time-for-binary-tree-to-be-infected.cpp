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
private:
    TreeNode* mark_Parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent,int &target) {

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetNode = NULL;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->val == target) {
                targetNode = node;
            }
            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        return targetNode;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* targetnode = mark_Parent(root, parent, start);
        queue<TreeNode*> q;
        q.push(targetnode);
        unordered_map<TreeNode*, int> vis;
        int time = 0;
        vis[targetnode]=1;
        while (!q.empty()) {
            int n = q.size();
            bool burned = false;
            while (n--) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = 1;
                    burned = true;
                }
                if (node->right && !vis[node->right]) {
                    vis[node->right] = 1;
                    q.push(node->right);
                    burned = true;
                }
                if (parent[node] && !vis[parent[node]]) {
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                    burned = true;
                }
            }
            if (burned) {
                time++;
            }
        }
        return time;
    }
};