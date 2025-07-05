//link: https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        int output = -1;

        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }

        for(auto& [count, freq]: map){
            if(count == freq){
                output = max(count, output);
            }
        }
    
        return output;
        
    }
};