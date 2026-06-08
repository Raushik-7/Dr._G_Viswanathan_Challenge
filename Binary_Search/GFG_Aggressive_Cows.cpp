class Solution {
	public:
	int aggressiveCows(vector<int> &stalls, int k) {
		// code here
		int n = stalls.size();
		sort(stalls.begin(), stalls.end());
		int start = 0, end, mid, ans;
		end = stalls[n - 1] - stalls[0];
		
		while (start <= end) {
			mid = start + (end - start)/2;
			int pos = stalls[0], count = 1;
			for (int i = 0; i<n; i++) {
				if (pos + mid <= stalls[i]) {
					count++;
					pos = stalls[i];
				}
			}
			if (count<k) {
				end = mid - 1;
			} else {
				ans = mid;
				start = mid + 1;
			}
		}
		return ans;
	}
};
