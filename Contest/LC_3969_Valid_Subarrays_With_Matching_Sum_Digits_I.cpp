class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
         vector<int> veltanoric = nums;

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                if (sum % 10 != x) {
                    continue;
                }

                long long temp = sum;

                while (temp > 9) {
                    temp /= 10;
                }

                if (temp == x) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
