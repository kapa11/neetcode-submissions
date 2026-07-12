class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for(int &val : nums){
            us.insert(val);
        }

        int largest = 0;
        for(const int &val : us){
            if(us.find(val-1) == us.end()){
                int len = 1;
                while(us.find(val + len) != us.end()){
                    len++;
                }
                largest = max(len, largest);
            }
            
        }
        return largest;
    }
};
