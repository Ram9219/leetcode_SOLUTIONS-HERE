/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>mp;
Node* dfs(Node *root){

    if(mp.count(root)){
        return mp[root];
    }
    Node *clone=new Node(root->val);
    mp[root]=clone;
    for(auto &it:root->neighbors){
        clone->neighbors.push_back(dfs(it));
    }
    return clone;
}
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        return dfs(node);
    }
};