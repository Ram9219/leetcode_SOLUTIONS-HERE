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
    // use the queuee and the map to store the order of the vertical nodes
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        // make a queue {root},{col,row}
        queue<pair<TreeNode*, pair<int, int>>> q;
        // now mak ea map to store and hanle the one by one vertical nodes
        map<int, map<int, multiset<int>>> mp;
        q.push({root,{0,0}}); // intially passing the 0 row and 0 col and root as null
        while (!q.empty()) {
            auto front=q.front();
            q.pop();
            TreeNode*node=front.first;
            int col=front.second.first;
            int row=front.second.second;
            mp[col][row].insert(node->val);
            //aaab left  me jaake dekh 
            if(node->left)q.push({{node->left},{col-1,row+1}});
            if(node->right)q.push({{node->right},{col+1,row+1}});
        }
        //now just we have to build the ans 
        for(auto&colpair:mp){
            vector<int>col;
            for(auto& rowpair:colpair.second){
                col.insert(col.end(),
                rowpair.second.begin(),
                rowpair.second.end()
                );
            }
            ans.push_back(col);
        }
        return ans;
    }
};