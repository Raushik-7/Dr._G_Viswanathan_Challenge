// Brute Force 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int index1 = 0; index1 < nums1.size(); index1++){
            int curr = nums1[index1];
            int nextGreater = -1;
            for(int i=0;i<nums2.size();i++){
                if(nums2[i] == curr){
                    for(int j= i+1;j<nums2.size();j++){
                        if(nums2[j] > curr){
                            nextGreater = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            result.push_back(nextGreater);
        }
        return result;
    }
};



//Hash map + Stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater_map;
        stack<int> s;
      
        for (int num : nums2) {
            // While stack is not empty and current num is greater than the top element
            while (!s.empty() && num > s.top()) {
                next_greater_map[s.top()] = num; // Save the relationship
                s.pop(); 
            }
            s.push(num); 
        }
        
        vector<int> result;
        for (int num : nums1) {
            if (next_greater_map.count(num)) {
                result.push_back(next_greater_map[num]);
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};
