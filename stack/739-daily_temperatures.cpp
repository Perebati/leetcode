//link https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);
        stack<pair<int, int>> stackOutput;

        for(int i = 0; i < temperatures.size(); i++){
            while (!stackOutput.empty() && temperatures[i] > stackOutput.top().first) {
                auto last = stackOutput.top();
                stackOutput.pop();
                output[last.second] = i - last.second;
            }
            stackOutput.push({temperatures[i], i});
            
        }
        return output;
    }
};