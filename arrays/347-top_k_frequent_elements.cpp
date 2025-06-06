//Link: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;

        for(auto num: nums){
            countMap[num]++;
        }

        auto comp = [](pair<int, int>& arg1, pair<int, int>& arg2){
            return arg1.second < arg2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);

        for(auto& map: countMap){
            heap.push({map.first, map.second});
        }

        vector<int> res;
        for(; k > 0; k--){
            res.push_back(heap.top().first);
            heap.pop();
        }

        return res;
    }
};