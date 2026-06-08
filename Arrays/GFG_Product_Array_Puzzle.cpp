class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res(n, 1);
        int left_prod = 1;
        for(int i=0;i<n;i++){
            res[i] = left_prod;
            left_prod *= arr[i];
        }
        
        int right_prod = 1;
        for(int i=n-1;i>=0;i--){
            res[i] *= right_prod;
            right_prod *= arr[i];
        }
        return res;
    }
};
