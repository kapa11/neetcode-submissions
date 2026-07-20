class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;

        unordered_set<char> us;
        int l=0, r=1, longest = 1;
        us.insert(s[l]);
        while(r<s.size()){
            if(us.find(s[r])==us.end()){
                us.insert(s[r]);
                longest = max(longest,(r-l+1));
                r++;
            }
            else{
                while(l=<r && s[l]!=s[r]){
                    us.erase(s[l]);
                    l++;
                }
            }
        }
        return longest;
    }
};
