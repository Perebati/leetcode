class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
    
            for(string itr: strs){
                string word = itr;
                sort(word.begin(), word.end());
                mp[word].push_back(itr);
            }
    
            vector<vector<string>> result;
            for(auto itr: mp){
                result.push_back(itr.second);
            }

            priority_queue<int> queue;
    
            return result;
        }
    };