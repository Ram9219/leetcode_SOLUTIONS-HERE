class Solution {
public:
    int count = 0;

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= right)
            temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }

    void countPairs(vector<int>& nums, int low, int mid, int high) {
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }
    }

    void mergesort(vector<int>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        countPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
};
