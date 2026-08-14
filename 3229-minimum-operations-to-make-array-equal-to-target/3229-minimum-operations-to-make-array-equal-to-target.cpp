class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        long long ans = 0;
        long long prev = 0;

        for (int i = 0; i < n; i++) {
            long long curr = (long long)target[i] - nums[i];

            if (curr > 0) {
                ans += max(0LL, curr - max(0LL, prev));
            }

            else if (curr < 0) {
                ans += max(0LL, -curr - max(0LL, -prev));
            }

            prev = curr;
        }

        return ans;
    }
};