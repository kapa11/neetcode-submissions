class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;

        for(int &val: nums){
            if(us.find(val) != us.end()){
                return true;
            }
            us.insert(val);
        }
        return false;
    }
};