//link: https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carData;

        for(int i = 0; i < position.size(); i++){
            carData.push_back({position[i], speed[i]});
        }

        sort(carData.begin(), carData.end());

        vector<double> timeStack;

        for(int i = carData.size() - 1; i >= 0; i--){
            timeStack.push_back((double)(target - carData[i].first) / carData[i].second);

            if (timeStack.size() >= 2 && timeStack.back() <= timeStack[timeStack.size() - 2]) {
                timeStack.pop_back();
            }  
        }

        return timeStack.size();
    }
};