//link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> s1Count;

        for(int i = 0; i < s1.length(); i++){
            s1Count[s1[i]]++;
        }

        for(int i = 0; i <= s2.length() - s1.length(); i++){
            unordered_map<char, int> s2Count;
            
            for(int j = i; j < i + s1.length(); j++){
                s2Count[s2[j]]++;
            }

            if (s1Count == s2Count) {
                return true;
            }

        }

        return false;
    }
};