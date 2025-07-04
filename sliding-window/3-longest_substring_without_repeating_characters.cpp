//link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> checkChar;

        int l = 0, r = 0;
        int substringSize = 0;

        while(r < s.length()){
            if(checkChar.find((char)s[r]) == checkChar.end()){ //não existe
                checkChar.insert((char)s[r]);
                substringSize = max((int)checkChar.size(), substringSize);
                r++;
            }else{ //existe
                checkChar.clear();
                l++;
                r = l;
            }
        }

        return substringSize;
    }
};