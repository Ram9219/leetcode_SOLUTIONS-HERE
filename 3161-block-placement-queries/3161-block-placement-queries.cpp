class Fenwick {
public:
    vector<int> bit;

    Fenwick(int n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] = max(bit[idx], val);
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & (-idx);
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = min(50000, (int)queries.size() * 3);

        set<int> obstacles = {0, LIMIT};

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        Fenwick ft(LIMIT + 2);

        auto it = obstacles.begin();

        while (next(it) != obstacles.end()) {
            int a = *it;
            int b = *next(it);

            ft.update(b, b - a);

            ++it;
        }

        vector<bool> ans;

        for (int i = queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 1) {

                int x = q[1];

                auto cur = obstacles.find(x);

                int prv = *prev(cur);

                auto nxtIt = next(cur);

                if (nxtIt != obstacles.end()) {
                    int nxt = *nxtIt;
                    ft.update(nxt, nxt - prv);
                }

                obstacles.erase(cur);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int prv = *prev(it);

                bool ok =
                    (ft.query(prv) >= sz) ||
                    (x - prv >= sz);

                ans.push_back(ok);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};