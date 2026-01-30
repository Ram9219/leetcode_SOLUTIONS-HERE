class Solution {
public:
    vector<int> BIT;
    int n;

    // BIT me value add karna
    void update(int i, int val) {
        while (i <= n) {
            BIT[i] += val;
            i += (i & -i);
        }
    }

    // prefix sum query (1 se i tak)
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= (i & -i);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz);

        // 🔹 Coordinate Compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        n = sorted.size();
        BIT.assign(n + 1, 0);

        // 🔹 Right se left traverse
        for (int i = sz - 1; i >= 0; i--) {
            int idx = lower_bound(sorted.begin(), sorted.end(), nums[i]) 
                      - sorted.begin() + 1;

            ans[i] = query(idx - 1); // kitne chhote hain
            update(idx, 1);         // current element add
        }
        return ans;
    }
};
