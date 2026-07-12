class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(int i = 0; i<nums.size(); i++){
            int pr = target - nums[i];
            if(m.find(pr) != m.end()){
                ans.push_back(m[pr]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
