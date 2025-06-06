// Link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //crio um unordered_map de string, vector<string>
        unordered_map<string, vector<string>> sortedHash;

        //ordeno as strings e armazeno na chave da hash e agrupo os anagramas
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            sortedHash[key].push_back(str);
        }

        //trasformo o hash em um vetor de strings e retorno a resposta
        vector<vector<string>> result;
        for(auto hash : sortedHash){
            result.push_back(hash.second);
        }

        return result;
        
    }
};