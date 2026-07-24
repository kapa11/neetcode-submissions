class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        int l = 0, r = k-1;
        
        while(r<nums.size()-1){
            r++;
            l++;

            while(!dq.empty() && dq.front()<l){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);

            res.push_back(nums[dq.front()]);
        }
        

        return res;
    }
};
