class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxFreq = 0, longest = 0;
        unordered_map<char,int> um;
        while(r<s.size()){
            um[s[r]]++;
            maxFreq = max(maxFreq,um[s[r]]);

            if((r-l+1) - maxFreq > k){
                um[s[l]]--;
                l++;
            }
            longest = max(longest, (r-l+1));
            r++;
        }
        return longest;
    }
};
