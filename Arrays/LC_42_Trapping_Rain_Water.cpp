class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = INT_MIN, index = 0;
        int n = height.size();

        //Finding th maximum height of abuilding
        for (int i = 0; i < n; i++) {
            if (height[i] > maxi) {
                maxi = height[i];
                index = i;
            }
        }

        //Storing Water from left till max height
        int leftMax = 0, water = 0;
        for (int i = 0; i < index; i++) {
            if (leftMax > height[i]) {
                water += leftMax - height[i];
            } else {
                leftMax = height[i];
            }
        }

        //Storing Water from right till highest building
        int rightMax = 0;
        for (int i = n - 1; i > index; i--) {
            if (rightMax > height[i]) {
                water += rightMax - height[i];
            } else {
                rightMax = height[i];
            }
        }
        return water;
    }
};
