class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 1, r = height.size()-2;
        int lMax = height[0], rMax = height[height.size()-1];

        while(l<=r){
            if(lMax<=rMax){
                ans += max(0, (lMax - height[l]));
                lMax = max(lMax, height[l]);
                l++;
            }
            else{
                ans += max(0, (rMax - height[r]));
                rMax = max(rMax, height[r]);
                r--;
            }
        }
        return ans;
    }
};
