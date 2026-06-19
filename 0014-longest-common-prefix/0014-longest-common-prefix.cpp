class Node {
public:
    Node* child[26];
    int childcount;
    bool isEnd;
    Node() {
        isEnd = false;
        childcount = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (node->child[i] == NULL) {
                node->child[i] = new Node();
                node->childcount++;
            }
            node = node->child[i];
        }
        node->isEnd = true;
    }
    string getLcp() {
        Node* node = root;
        string ans = "";
        while (node->childcount == 1 && !node->isEnd) {
            for (int i = 0; i < 26; i++) {
                if (node->child[i]) {
                    ans += char('a' + i);
                    node = node->child[i];
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for (auto ch : strs) {
            t.insert(ch);
        }
        return t.getLcp();
    }
};