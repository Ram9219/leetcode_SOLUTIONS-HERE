class Solution {
public:

    vector<vector<string>> ans;

    void dfs(string word,
             string beginWord,
             unordered_map<string, int>& mp,
             vector<string>& seq) {

        if (word == beginWord) {

            reverse(seq.begin(), seq.end());

            ans.push_back(seq);

            reverse(seq.begin(), seq.end());

            return;
        }

        int steps = mp[word];

        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (mp.find(word) != mp.end() &&
                    mp[word] + 1 == steps) {

                    seq.push_back(word);

                    dfs(word, beginWord, mp, seq);

                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;

        unordered_map<string, int> mp;

        q.push(beginWord);

        mp[beginWord] = 1;

        st.erase(beginWord);

        // BFS
        while (!q.empty()) {

            string word = q.front();

            int steps = mp[word];

            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.count(word)) {

                        q.push(word);

                        st.erase(word);

                        mp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        // DFS to build paths
        if (mp.find(endWord) != mp.end()) {

            vector<string> seq;

            seq.push_back(endWord);

            dfs(endWord, beginWord, mp, seq);
        }

        return ans;
    }
};