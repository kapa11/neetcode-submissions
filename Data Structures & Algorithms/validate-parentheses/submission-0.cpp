class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> lut = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
        stack<int> st;
        for(char &c : s){
            if(lut[c]<0){
                st.push(lut[c]);
            }
            else{
                if(!st.empty() && lut[c] + st.top() == 0){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
