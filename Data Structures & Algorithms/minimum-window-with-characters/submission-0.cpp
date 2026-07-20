class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";

        unordered_map<char,int> tFreq;
        unordered_map<char,int> sWindowFreq;

        for(char &ch : t){
            tFreq[ch]++;
        }

        int need = tFreq.size();
        int matches = 0;

        int l = 0, r = 0, start = 0, minWindow = INT_MAX;

        while(r<s.size()){
            sWindowFreq[s[r]]++;

            if(tFreq.find(s[r]) != tFreq.end() && sWindowFreq[s[r]] == tFreq[s[r]]){
                matches++;
            }
            while(matches==need){
                if(r-l+1 < minWindow){
                    minWindow = r-l+1;
                    start = l;
                }

                sWindowFreq[s[l]]--;
                
                if(tFreq.find(s[l]) != tFreq.end() && sWindowFreq[s[l]]<tFreq[s[l]]){
                    matches--;
                } 
                l++;
            }
            r++;
        }

        if(minWindow==INT_MAX) return "";
        else return s.substr(start,minWindow);
    }
};
