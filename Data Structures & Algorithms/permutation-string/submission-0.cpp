class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        vector<int> s1Freq(26,0);
        vector<int> s2SubFreq(26,0);

        for(char &ch : s1){
            s1Freq[ch-'a']++;
        }
        for(int i = 0; i<s1.size(); i++){
            s2SubFreq[s2[i]-'a']++;
        }

        int l = 0, r = s1.size()-1;
        while(r<s2.size()){
            int match = 1;
            for(int i=0; i<26; i++){
                if(s1Freq[i]!=s2SubFreq[i]){
                    match = 0;
                    break;
                }
            }
            if(match) return true;
            else{
                if(r == s2.size()-1) break;
                s2SubFreq[s2[l]-'a']--;
                l++;
                r++;
                s2SubFreq[s2[r]-'a']++;
            } 
            
        }
        return false;
    }
};
