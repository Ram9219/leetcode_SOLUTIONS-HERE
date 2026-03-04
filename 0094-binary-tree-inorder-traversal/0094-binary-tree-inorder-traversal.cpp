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
    // we will use the same logic as LNR
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root; // jisse current node track ho paye
        while (true) {
            if (node != NULL) {
                st.push(node); // agar node null nahi hai that means koi value
                               // hai push kado
                node = node->left; // aur node ko left me badha do
            } else {
                if (st.empty() == true)
                    break; // agar stack khatam ho chuka hai to ruk  kjao
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};