class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total_time = 0;
        for(int i=0;i<n-1;i++){
            int gap = timeSeries[i+1] - timeSeries[i];
            total_time += min(duration, gap);
        }
        return total_time + duration;  //The last attack never get interrupted, so i have added the full length of duration
    }
};
