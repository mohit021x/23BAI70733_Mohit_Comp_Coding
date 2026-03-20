class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 0;

        for (int i = 0; i < nums.size(); i++) {
            right = max(right, nums[i]);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long ops = 0;

            for (int i = 0; i < nums.size(); i++) {
                ops += (nums[i] - 1) / mid;
            }

            if (ops > maxOperations) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};