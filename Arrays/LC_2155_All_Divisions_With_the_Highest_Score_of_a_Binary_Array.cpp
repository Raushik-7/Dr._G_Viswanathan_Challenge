class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        int total_ones = 0;
        for(int num : nums){
            if(num == 1){
                total_ones++;
            }
        }
        int max_score = -1;
        int left_zero = 0;
        int right_ones = total_ones;

        for(int i=0;i<=n;i++){
            int current_score =  left_zero + right_ones;

            if(current_score > max_score){
                max_score = current_score;
                result = {i};
            }else if(current_score == max_score){
                result.push_back(i);
            }

            if(i<n){
                if(nums[i] == 0){
                    left_zero++;
                }else{
                    right_ones--;
                }
            }
        }
        return result;
    }
};
