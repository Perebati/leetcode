class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for(char c: s){
            if(alphanum(c)){
                str += c;
            }
        }

        int l = 0, r = str.length() - 1;

        while(l < r){
            if(tolower(str[l]) != tolower(str[r])){
                return false;
            }

            l++; r--;
        }

        return true;
    }

    bool alphanum(char c){
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9' );
    }
};