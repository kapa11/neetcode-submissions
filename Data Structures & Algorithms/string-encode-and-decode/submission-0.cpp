class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto &str : strs){
            s += to_string(str.size()) + "_" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string countStr;

        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j]!='_'){
                j++;
            }
            countStr = s.substr(i,j-i);
            int len = stoi(countStr);
            string str = s.substr(j+1, len);
            strs.push_back(str);

            i = j+len+1;
        }
        return strs;
    }
};
