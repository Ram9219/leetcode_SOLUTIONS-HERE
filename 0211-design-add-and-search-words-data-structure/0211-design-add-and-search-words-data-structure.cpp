class Node {
public:
    Node* child[26];
    bool isEnd;

    Node() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class WordDictionary {
public:

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->child[idx] == NULL) {
                node->child[idx] = new Node();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool solve(string& word, int pos, Node* node) {

        if (node == NULL)
            return false;

        if (pos == word.size())
            return node->isEnd;

        char ch = word[pos];

        // Normal character
        if (ch != '.') {

            int idx = ch - 'a';

            return solve(word, pos + 1, node->child[idx]);
        }

        // Wildcard
        for (int i = 0; i < 26; i++) {

            if (node->child[i] != NULL) {

                if (solve(word, pos + 1, node->child[i]))
                    return true;
            }
        }

        return false;
    }

    bool search(string word) {
        return solve(word, 0, root);
    }
};