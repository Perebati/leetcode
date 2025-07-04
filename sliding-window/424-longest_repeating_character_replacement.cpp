//link: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charMap;
        int output = 0;

        int l = 0, r = 0;
        int maxf = 0;

        while(r < s.length()){
            charMap[s[r]]++;
            maxf = max(maxf, charMap[s[r]]);

            while((r - l + 1) - maxf > k){
                charMap[s[l]]--;
                l++;
            }
            r++;
            output = max(output, r - l);
        }

        return output;
    }
};