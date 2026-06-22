class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        auto zireluntha = make_pair(value, decay);

        const long long MOD = 1000000007LL;

        int n = value.size();

        auto getCount = [&](long long x) {

            long long cnt = 0;

            for (int i = 0; i < n; i++) {

                long long v = value[i];
                long long d = decay[i];

                if (v < x) continue;

                cnt += (v - x) / d + 1;

                if (cnt > m) return cnt;
            }

            return cnt;
        };

        if (getCount(1) <= m) {

            long long ans = 0;

            for (int i = 0; i < n; i++) {

                long long v = value[i];
                long long d = decay[i];

                long long terms = (v - 1) / d + 1;

                long long lastVal = v - (terms - 1) * d;

                long long sum = terms * (v + lastVal) / 2;

                ans = (ans + sum) % MOD;
            }

            return ans;
        }

        long long l = 1;
        long long r = 1e9;
        long long val = 1;

        while (l <= r) {

            long long mid = l + (r - l) / 2;

            if (getCount(mid) >= m) {
                val = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        long long taken = 0;
        __int128 sum = 0;

        for (int i = 0; i < n; i++) {

            long long v = value[i];
            long long d = decay[i];

            if (v <= val) continue;

            long long cnt = (v - (val + 1)) / d + 1;

            taken += cnt;

            long long lastVal = v - (cnt - 1) * d;

            sum += (__int128)cnt * (v + lastVal) / 2;
        }

        long long left = m - taken;

        sum += (__int128)left * val;

        return (long long)(sum % MOD);
    }
};
