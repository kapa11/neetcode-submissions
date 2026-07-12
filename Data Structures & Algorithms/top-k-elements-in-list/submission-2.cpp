class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int &x : nums){
            freq[x]++;
        }

         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &p : freq){
            pq.push({p.second,p.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        for(int i = 0; i<k; i++){
            auto p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }

        return ans;
    }
};
