class Solution {
public:
    bool isPalindrome(string s) {
        string s1;

        for (char c : s) {
            if (isalnum(c)){ //is alphanumeric?
                s1 += tolower(c); //tolower returns int! which is converted back to char (ASCII mapping)
            }      
        }
            
        int l = 0, r = s1.size() - 1;

        while(l<r){
            if(s1[l] != s1[r]) return false;

            l++;
            r--;
        }
        return true;
    }
};
