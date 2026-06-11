class Solution {
private:
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;

    // Build Sparse Table for O(1) Range Maximum and Minimum Queries
    void buildSparseTable(const vector<int>& nums, int n) {
        int max_log = log2(n) + 1;
        st_max.assign(max_log, vector<int>(n));
        st_min.assign(max_log, vector<int>(n));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            st_max[0][i] = nums[i];
            st_min[0][i] = nums[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
                st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    // O(1) query to get the value of subarray nums[L..R]
    int queryVal(int L, int R) {
        int j = lg[R - L + 1];
        int mx = max(st_max[j][L], st_max[j][R - (1 << j) + 1]);
        int mn = min(st_min[j][L], st_min[j][R - (1 << j) + 1]);
        return mx - mn;
    }

    struct SubarrayState {
        int val;
        int L;
        int R;
        
        // Max-heap prioritizes the largest subarray value
        bool operator<(const SubarrayState& other) const {
            return val < other.val;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparseTable(nums, n);

        priority_queue<SubarrayState> max_heap;

        // Monotonicity: For a fixed L, the largest value is always at R = n - 1
        for (int l = 0; l < n; l++) {
            int val = queryVal(l, n - 1);
            max_heap.push({val, l, n - 1});
        }

        long long total_value = 0;

        // Extract the top K elements
        while (k > 0 && !max_heap.empty()) {
            SubarrayState curr = max_heap.top();
            max_heap.pop();

            total_value += curr.val;
            k--;

            // If we can shrink the right boundary for this specific L list, push the next best element
            if (curr.R > curr.L) {
                int next_r = curr.R - 1;
                int next_val = queryVal(curr.L, next_r);
                max_heap.push({next_val, curr.L, next_r});
            }
        }

        return total_value;
    }
};
