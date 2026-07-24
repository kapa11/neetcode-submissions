class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0; i<k; i++){
            pq.push({nums[i],i});
        }

        int l = 0, r = k-1;
        vector<int> res;
        res.push_back(pq.top().first);

        while(r<nums.size()-1){
            r++;
            pq.push({nums[r], r});
            l++;

            while(pq.top().second<l){
                pq.pop();
            }

            res.push_back(pq.top().first);
        }

        return res;
    }
};
