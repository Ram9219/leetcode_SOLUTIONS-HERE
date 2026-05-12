class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& nums) {
        queue<pair<string, int>> q;
        // initially start with the beginword with steps as 1
        q.push({beginWord, 1});
        unordered_set<string> st(begin(nums), end(nums));
         st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;

            // now we are going to genrate the evry possible word of that size
            // is available in the set
            for (int i = 0; i < word.size(); i++) {
                char org = word[i];
                // hitting start form the first chaacter and then like wise for
                // every char a to z
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // if find in the set then just store and erase from their
                    // not to conflicyt in the nex level
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = org;
            }
        }
        // if nothing is found then
        return 0;
    }
};