class Solution {
public:
    vector<int> ans;

    void merge(vector<pair<int,int>>& arr, int left, int mid, int right) {
        vector<pair<int,int>> temp;

        int i = left;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                ans[arr[i].second] += smaller;
                temp.push_back(arr[i++]);
            } else {
                smaller++;
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += smaller;
            temp.push_back(arr[i++]);
        }

        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    void divide(vector<pair<int,int>>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        divide(arr, left, mid);
        divide(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        ans.assign(n, 0);

        vector<pair<int,int>> arr; // {value,index}

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        divide(arr, 0, n - 1);

        return ans;
    }
};