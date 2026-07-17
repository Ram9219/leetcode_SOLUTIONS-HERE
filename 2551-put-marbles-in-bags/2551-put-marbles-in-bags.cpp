class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (int i = 1; i < weights.size(); i++) {
            int sum = 0;
            sum += weights[i] + weights[i - 1];
            maxheap.push(sum);
            minheap.push(sum);
        }

        long long mx = 0;
        long long mn = 0;
        for (int i = 0; i < k - 1; i++) {
            mx += maxheap.top();
            maxheap.pop();
            mn += minheap.top();
            minheap.pop();
        }

        return mx - mn;
    }
};